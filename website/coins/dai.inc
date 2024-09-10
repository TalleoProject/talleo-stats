<?php
$height += 206;
$ticker = "DAI";
$coin = "Dai stablecoin";
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
<tr><th style="text-align:left;">Website:</th><td style="text-align:left;"><a href="https://makerdao.com">makerdao.com</a></td></tr>
<tr><th style="text-align:left;">Contract:</th><td style="text-align:left;">0x6b175474e89094c44da98b954eedeac495271d0f (Ethereum)</td></tr>
</table>
</div>
