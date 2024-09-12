<?php
$height += 206;
?>
<div style="height:200px;margin-top:6px;">
<span id="icon"><img src="https://cryptoradar.exchange/img/crx-icon128.png" width=32></span><span style="font-size:32px;">&nbsp;CryptoRadar Exchange</span>
<br>
<table>
<tr><th>Website:</th><td>
<?php
if (array_key_exists("m", $_REQUEST) && array_key_exists(strtolower($_REQUEST["m"]), $markets) && array_key_exists("crx", $markets[strtolower($_REQUEST["m"])])) {
  echo "<a href='https://cryptoradar.exchange/crx/markets?m=".strtolower($_REQUEST["m"])."' target='_blank'>cryptoradar.exchange/crx/markets?m=".strtolower($_REQUEST["m"])."</a>";
} else if (array_key_exists("c", $_REQUEST) && array_key_exists(strtolower($_REQUEST["c"]), $coins) && array_key_exists("crx", $coins[strtolower($_REQUEST["c"])])) {
  echo "<a href='https://cryptoradar.exchange/crx/markets?search=".strtolower($_REQUEST["c"])."' target='_blank'>cryptoradar.exchange/crx/markets?search=".strtolower($_REQUEST["c"])."</a>";
} else {
  echo "<a href='https://cryptoradar.exchange/crx/home' target='_blank'>cryptoradar.exchange/crx/home</a>";
}
?>
</td></tr>
</table>
</div>
