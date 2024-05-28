<?php
header('Content-Type: text/html');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>
<head>
 <title>Portfolio PHP-Themen Felix M. Röhr</title>
 <link rel="stylesheet" href="main.css" type="text/css">
</head>
<body text="#000000" bgcolor="#FFFFFF">

<table align="center" width="90%" border="0" cellpadding="0" cellspacing="0">
 <tr>
  <td colspan="2" align="center"><h1>Portfolio PHP-Themen Felix M. Röhr</h1></td>
 </tr>
 <tr valign="top">
  <td>

   <table>
    <tr>
     <td><br><a href="index.php?value=0">Startseite</a></td>
    </tr>
    <tr>
     <td><br><a href="index.php?value=1">Karten</a></td>
    <tr>
     <td><br><a href="index.php?value=2">Rätsel</a></td>
    </tr>
    <tr>
     <td><br><a href="index.php?value=3">Personal</a></td>
    </tr>
    </tr>
   </table>

  </td>
  <td>
  <?php
   $wahl=0;
   if (isset($_GET["value"])) {
    $wahl=$_GET["value"];
   }
   switch($wahl){
   case 1:include "thema1.php"; break;
   case 2:include "thema2.php"; break;
   case 3:include "thema3.php"; break;    
   default:include "thema0.php";
   }
  ?>
  </td>
 </tr>
</table>

</body>
</html>