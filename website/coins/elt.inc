<?php
$height += 206;
$ticker = "ELT";
$coin = "Electron";
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
</div>