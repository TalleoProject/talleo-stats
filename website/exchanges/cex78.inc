<?php
$height += 206;
?>
<div style="height:200px;margin-top:6px;">
<span id="icon"><img src="https://cex78.com/img/CEX78_ver3-01-200.png" width=36></span><span style="font-size:32px;vertical-align:top;">&nbsp;CEX78</span>
<br>
<table>
<tr><th>Website:</th><td>
<?php
if (array_key_exists("m", $_REQUEST) && array_key_exists(strtolower($_REQUEST["m"]), $markets) && array_key_exists("cex78", $markets[strtolower($_REQUEST["m"])])) {
  echo "<a href='https://cex78.com/cex/markets?m=".strtolower($_REQUEST["m"])."' target='_blank'>cex78.com/cex/markets?m=".strtolower($_REQUEST["m"])."</a>";
} else if (array_key_exists("c", $_REQUEST) && array_key_exists(strtolower($_REQUEST["c"]), $coins) && array_key_exists("cex78", $coins[strtolower($_REQUEST["c"])])) {
  echo "<a href='https://cex78.com/cex/markets?search=".strtolower($_REQUEST["c"])."' target='_blank'>cex78.com/cex/markets?search=".strtolower($_REQUEST["c"])."</a>";
} else {
  echo "<a href='https://cex78.com/crx/home' target='_blank'>cex78.com/cex/home</a>";
}
?>
</td></tr>
</table>
</div>
