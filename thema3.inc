<?php
 //connection-string
 $con=mysqli_connect('localhost','user','');
 $db=mysqli_select_db($con,'lenne2');

 header('Content-Type:text/html;charset=ISO-8859-1');
?>


<table align="center" width="800" cellspacing="0" cellpadding="0">
 <tr>
  <td align="center"><h1>Personalverwaltung</h1></td>
 </tr>
 <tr>
  <td>
  <form method="post">
  <!-- Dateneingabe -->
  <?php

    $_fehler=0;
    if (isset($_POST["eintragen_x"])) {
     if (isset($_POST["nachname"]) && isset($_POST["vorname"])) {
      $_nachname=$_POST["nachname"];
      $_vorname=$_POST["vorname"];
      $_geschlecht=$_POST["geschlecht"];
      $_gehalt=$_POST["gehalt"];
      if (($_nachname!="") && !empty($_vorname)) {
       mysqli_query($con,"insert into tj_personal(nachname,vorname,geschlecht,lohn) values ('$_nachname','$_vorname','$_geschlecht',$_gehalt)");
      }}
      else {
       $_fehler=1;
     }
    }

  ?>
  <!-- Änderungsabfrage -->
  <?php
   if (isset($_GET["aendern"])){
    $merker=$_GET["aendern"];
    $rs=mysqli_query($con,"select * from tj_personal where id=".$merker);
    $zeile=mysqli_fetch_row($rs);
   }
  ?>

  <!-- Datensatz aktualisieren -->

  <?php
   if (isset($_POST["aktualisieren_y"])){
    if (isset($_POST["nachname"]) && isset($_POST["vorname"])) {
      $_nachname=$_POST["nachname"];
      $_vorname=$_POST["vorname"];
      $_geschlecht=$_POST["geschlecht"];
      $_gehalt=$_POST["gehalt"];
      //' vor bzw. hinter " hat gefehlt




      if (($_nachname!="") && !empty($_vorname)) {
       mysqli_query($con,"update tj_personal set nachname='".$_POST['nachname']."',vorname='".$_POST['vorname']."',geschlecht='".$_POST['geschlecht']."',lohn=".$_POST['gehalt']." where id=".$merker);
      }}
      else {
       $_fehler=2;
     }
   }
  ?>

  <!-- Löschabfrage -->
  <?php
   if (isset($_GET["loeschen"])){
    $merker=$_GET["loeschen"];
    $rs=mysqli_query($con,"select * from tj_personal where id=".$merker);
    $zeile=mysqli_fetch_row($rs);
  ?>

  <table width="300" bgcolor="#ffcccc" align="center">
   <tr>
    <td>Wollen Sie <?php echo $zeile[1]." ".$zeile[2]; ?> wirklich l&ouml;schen?</td>
   </tr>
   <tr>
    <td align="center"><input type="submit" name="ja" value="ja">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" name="nein" value="nein"></td>
   </tr>
  </table>
  <br>
  <?php
   }
  ?>

  <!-- tatsächliches Löschen aus der Datenbank -->

  <?php
   if (isset($_POST["ja"])) {
    mysqli_query($con,"delete from tj_personal where id=".        $merker);
    echo '<meta http-equiv="refresh" content="0;URL=index.php?value=3">';
   }
   if (isset($_POST["nein"])) {
    header("refresh:0;URL=index.php?value=3");
   }
  ?>

  <table align="center" border="0">
   <tr>
    <td>Nachname:</td>
    <td width="5"></td>
    <td><input type="text" name="nachname" value="<?php
     if (isset($_GET["aendern"])) {
      echo $zeile[1];
     }
    ?>"></td>
    <td width="10"></td>
    <td>Vorname:</td>
    <td width="5"></td>
    <td><input type="text" name="vorname" value="<?php
     if (isset($_GET["aendern"])) {
      echo $zeile[2];
     }
    ?>"></td>
    <td width="5"></td>
    <td width="20"></td>
   </tr>
   <tr>
    <td>Geschlecht:</td>
    <td></td>
    <td><input type="text" name="geschlecht" value="<?php
     if (isset($_GET["aendern"])) {
      echo $zeile[4];
     }
    ?>"></td>
    <td></td>
    <td>Gehalt:</td>
    <td></td>
    <td><input type="text" name="gehalt" value="<?php
     if (isset($_GET["aendern"])) {
      echo $zeile[3];
     }
    ?>"></td>
    <td></td>
    <td><?php
     if (isset($_GET["aendern"])){
    ?>
    <input type="image" name="aktualisieren" src="images/document_save.png" width="16">
    <?php
     } else {
    echo "<input type='image' name='eintragen' src='images/b_add.png'>";
     }
    ?>
    </td>
   </tr>
  </table>

  <br><br>

  <!-- Datenausgabe -->
  <table align="center" cellspacing="0">
   <tr bgcolor="#aaaaaa">
    <td width="80">lfd. Nummer</td>
    <td width="80">Nachname</td>
    <td width="80">Vorname</td>
    <td width="50">gesch.</td>
    <td width="80">Gehalt</td>
    <td></td>
    <td></td>
   </tr>

   <?php
   $rs=mysqli_query($con,"select * from tj_personal");
   for ($i=0;$i<mysqli_num_rows($rs);$i++) {
    $zeile=mysqli_fetch_row($rs);
   ?>

   <tr>
    <td><?php echo $zeile[0]; ?></td>
    <td><?php echo $zeile[1]; ?></td>
    <td><?php echo $zeile[2]; ?></td>
    <td><?php echo $zeile[4]; ?></td>
    <td><?php echo $zeile[3]; ?></td>
    <td><a href="index.php?value=3&loeschen=<?php echo $zeile[0]; ?>"><img src="images/b_drop.png"></a></td>
    <td><a href="index.php?value=3&aendern=<?php echo $zeile[0]; ?>"><img src="images/b_edit.png"></a></td>
   </tr>

   <?php
    }
   ?>

  </table>
  </form>
  </td>
 </tr>
</table>