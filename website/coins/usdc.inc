<?php
$height += 206;
$ticker = "USDC";
$coin = "USD Coin";
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
<tr><th style="text-align:left;" rowspan="2" valign="top">Contract:</th><td>0x8ac76a51cc950d9822d68b83fe1ad97b32cd580d (BSC)</td></tr>
<tr><td style="text-align:left;">0xa0b86991c6218b36c1d19d4a2e9eb0ce3606eb48 (Ethereum)</td></tr>
</table>
</div>
