<table width="100%">
 <tr>
  <td align="center"><a href="index.php?value=1&karte=1">Ass</a></td>


  <td align="center" rowspan="5"><?php
   $kwahl=1;
   if (isset($_GET["karte"])) {
    $kwahl=$_GET["karte"];
   }
   switch($kwahl){
   case 2:echo '<img src="images/zwei.jpg">'; break;
   case 3:echo '<img src="images/drei.jpg">'; break;
   case 4:echo '<img src="images/vier.jpg">'; break;
   case 5:echo '<img src="images/fuenf.jpg">'; break;
   case 6:echo '<img src="images/sechs.jpg">'; break;
   case 7:echo '<img src="images/sieben.jpg">'; break;
   case 8:echo '<img src="images/acht.jpg">'; break;
   case 9:echo '<img src="images/neun.jpg">'; break;
   case 10:echo '<img src="images/zehn.jpg">'; break;
   case 11:echo '<img src="images/bube.jpg">'; break;
   case 12:echo '<img src="images/dame.jpg">'; break;
   case 13:echo '<img src="images/koenig.jpg">'; break;
   default:echo '<img src="images/ass.jpg">';
   }
  ?></td>



  <td align="center"><a href="index.php?value=1&karte=6">Sechs</a></td>
 </tr>
 <tr>
  <td align="center"><a href="index.php?value=1&karte=2">Zwei</a></td>
  <td align="center"><a href="index.php?value=1&karte=7">Sieben</a></td>
 </tr>
 <tr>
  <td align="center"><a href="index.php?value=1&karte=3">Drei</a></td>
  <td align="center"><a href="index.php?value=1&karte=8">Acht</a></td>
 </tr>
 <tr>
  <td align="center"><a href="index.php?value=1&karte=4">Vier</a></td>
  <td align="center"><a href="index.php?value=1&karte=9">Neun</a></td>
 </tr>
 <tr>
  <td align="center"><a href="index.php?value=1&karte=5">F&uuml;nf</a></td>
  <td align="center"><a href="index.php?value=1&karte=10">Zehn</a></td>
 </tr>
 <tr height="35">
  <td align="center"><a href="index.php?value=1&karte=11">Bube</a></td>
  <td align="center"><a href="index.php?value=1&karte=12">Dame</a></td>
  <td align="center"><a href="index.php?value=1&karte=13">K&ouml;nig</a></td>
 </tr>
</table>