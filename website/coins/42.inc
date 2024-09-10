<?php
$height += 206;
$ticker = "42";
$coin = "42-coin";
$image = "https://cryptoradar.exchange/img/icon-".strtolower($ticker).".png";
?>
<div style="height:200px;margin-top:6px;">
<span id="icon">
<?php
echo '<img src="'.$image.'" width=32>';
?>
</span><span style="font-size:32px;">&nbsp;
<?php
echo $coin; 
?>
</span>
<br />
<table>
<tr><th style="text-align:left;">Website:</th><td style="text-align:left;"><a href="https://42-coin.org">42-coin.org</a></td></tr>
</table>
</div>
