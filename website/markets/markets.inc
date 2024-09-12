<?php
$height += 206;
function makemarketlink($market, $exchange) {
  if ($exchange == "cex78") {
    return "<a href='https://cex78.com/cex/markets?m=".$market."' target='_blank'>cex78.com/cex/markets?m=".$market."</a>";
  } else if ($exchange == "crx") {
    return "<a href='https://cryptoradar.exchange/crx/markets?m=".$market."' target='_blank'>cryptoradar.exchange/crx/markets?m=".$market."</a>";
  } else {
    return "N/A";
  }
}
?>
<div style="margin-top:6px;height:200px;">
<?php
if (array_key_exists("m", $_REQUEST) && array_key_exists($_REQUEST["m"], $markets)) {
  echo "<span style='font-size:32px;'>".strtoupper($_REQUEST["m"])."</span>";
  echo "<br />"; 
  echo "<table>";
  $numexchanges = count($markets[$_REQUEST["m"]]);
  $n = 0;
  foreach($markets[$_REQUEST["m"]] as $key => $value) {
    echo "<tr>";
    if ($n == 0) {
      echo "<th rowspan='".$numexchanges."' valign='top'>Website:</th>";
    }
    echo "<td>".makemarketlink($_REQUEST["m"], $key)."</td>";
    $n++;
  }
  echo "</table>";

}
?>
</div>
