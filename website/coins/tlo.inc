<?php
$height += 206;
$circulating = fetch("https://explorer.talleo.org/api/get_circulating_coins");
?>
<div style="height:200px;margin-top:6px;">
<link href="https://fonts.googleapis.com/css2?display=swap&amp;family=Courgette" rel="stylesheet">
<span id="icon"><img src="https://cryptoradar.exchange/img/icon-tlo.png" width=32></span><span style="font-size:32px;font-family:Courgette;">&nbsp;Talleo</span>
<br />
<table>
<tr><th style="text-align:left;">Website:</th><td style="text-align:left;"><a href="https://www.talleo.org">www.talleo.org</a></td></tr>
<tr><th style="text-align:left;">Total supply:</th><td style="text-align:right;">300000000.00 TLO</td></tr>
<tr><th style="text-align:left;">Circulating supply:</th><td style="text-align:right;"><?php echo ($circulating["circulatingCoins"]/100)." TLO"; ?></td></tr>
</table>
</div>
