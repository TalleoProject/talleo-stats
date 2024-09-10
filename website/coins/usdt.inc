<?php
$height += 206;
$ticker = "USDT";
$coin = "USD Tether";
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
<tr><th style="text-align:left;" rowspan="2" valign="top">Contract:</th><td>0x55d398326f99059ff775485246999027b3197955 (BSC)</td></tr>
<tr><td style="text-align:left;">0xdac17f958d2ee523a2206206994597c13d831ec7 (Ethereum)</td></tr>
</table>
</div>
