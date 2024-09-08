<?php
$exchanges = Array("cex78" => "CEX78", "crx" => "CryptoRadar");

function fetch($url) {
  $curl = curl_init();
  curl_setopt_array($curl, array(
    CURLOPT_URL => $url,
    CURLOPT_RETURNTRANSFER => true,
    CURLOPT_TIMEOUT => 30,
    CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
    CURLOPT_CUSTOMREQUEST => "GET",
    CURLOPT_HTTPHEADER => array(
      "cache-control: no-cache"
    )
  ));

  $response = curl_exec($curl);
  $err = curl_error($curl);
  curl_close($curl);
  $response = json_decode($response, true);
  return $response;
}

function makelink($market) {
  $coins = explode('-', $market);
  if (array_key_exists("c", $_REQUEST) && strtoupper($_REQUEST["c"]) == strtoupper($coins[0])) {
    $str  = strtoupper($coins[0]);
  } else {
    $str  = "<a href='?c=".$coins[0];
    if (array_key_exists("e", $_REQUEST)) {
      $str .= "&e=".$_REQUEST["e"];
    }
    $str .= "'>".strtoupper($coins[0])."</a>";
  }
  $str .= "-";
  if (array_key_exists("c", $_REQUEST) && strtoupper($_REQUEST["c"]) == strtoupper($coins[1])) {
    $str .= strtoupper($coins[1]);
  } else {
    $str .= "<a href='?c=".$coins[1];
    if (array_key_exists("e", $_REQUEST)) {
      $str .= "&e=".$_REQUEST["e"];
    }
    $str .= "'>".strtoupper($coins[1])."</a>";
  }
  return $str;
}

function exchangename($exchange) {
  global $exchanges;
  if (array_key_exists(strtolower($exchange), $exchanges)) return $exchanges[strtolower($exchange)];
  return "";
}

function exchangelink($exchange) {
  if (array_key_exists("e", $_REQUEST)) {
    $str = exchangename($exchange);
  } else {
    $str = "<a href='?";
    if (array_key_exists("c", $_REQUEST)) {
      $str .= "c=".$_REQUEST["c"]."&";
    }
    if (array_key_exists("m", $_REQUEST)) {
      $str .= "m=".$_REQUEST["m"]."&";
    }
    $str .= "e=".$exchange."'>".exchangename($exchange)."</a>";
  }
  return $str;
}

$cex_markets = fetch("https://cex78.com/api/markets.json");
$crx_markets = fetch("https://cryptoradar.exchange/api/markets.json");
$markets = Array();
$coins = Array();
foreach($cex_markets as $key => $value) {
  $markets[$value["id"]]["cex78"] = $value;
}
foreach($crx_markets as $key => $value) {
  $markets[$value["id"]]["crx"] = $value;
}
if (array_key_exists("json", $_REQUEST)) {
  header("Content-Type: application/json");
  var_dump($markets);
} else {
  ksort($markets);
  foreach($markets as $key => $value) {
    $pair = explode("-", $key);
    if (!array_key_exists($pair[0], $coins)) {
      $coins[$pair[0]] = Array();
    }
    if (!array_key_exists($pair[1], $coins)) {
      $coins[$pair[1]] = Array();
    }
  }
  echo "<html>
        <head>
        <title>Statistics</title>
        </head>
        <body style='margin-top:-6px;'>";
  $height = 40;
  if (array_key_exists("e", $_REQUEST) && array_key_exists(strtolower($_REQUEST["e"]), $exchanges)) {
    if (file_exists("exchanges/".strtolower($_REQUEST["e"]).".inc")) {
      include("exchanges/".strtolower($_REQUEST["e"]).".inc");
    }
  } else if (array_key_exists("c", $_REQUEST) && array_key_exists(strtolower($_REQUEST["c"]), $coins)) {
    if (file_exists("coins/".strtolower($_REQUEST["c"]).".inc")) {
      include("coins/".strtolower($_REQUEST["c"]).".inc");
    }
  } else if (array_key_exists("m", $_REQUEST) && array_key_exists(strtolower($_REQUEST["m"]), $markets)) {
    if (file_exists("markets/".strtolower($_REQUEST["m"]).".inc")) {
      include("markets/".strtolower($_REQUEST["m"]).".inc");
    }
  }
  echo "<div style='height:calc(100% - ".$height."px);overflow-y:auto;'>
        <table>
        <thead style='position:sticky;top:2;background-color: #f2f2f2;'>
        <tr><th>Market</th><th>Exchange</th><th>Price</th><th>Low</th><th>High</th><th>Volume</th></tr>
        </thead>
        <tbody>";
  foreach($markets as $key => $value) {
    $pair = explode("-", $key);
    if (array_key_exists("c", $_REQUEST) && $pair[0] != strtolower($_REQUEST['c']) && $pair[1] != strtolower($_REQUEST['c'])) {
      continue;
    }
    if (array_key_exists("m", $_REQUEST) && $key != strtolower($_REQUEST['m'])) {
      continue;
    }
    $num = 0;
    if (array_key_exists("cex78", $value) && (!array_key_exists("e", $_REQUEST) || $_REQUEST['e'] == "cex78")) {
      echo "<tr>";
      echo "<td rowspan=".(array_key_exists("e", $_REQUEST) ? 1 : count($value))." valign='top'>".makelink($key)."</td>";
      echo "<td>".exchangelink("cex78")."</td>";
      echo "<td align='right'>".$value["cex78"]["price"]."</td>";
      echo "<td align='right'>".$value["cex78"]["low"]."</td>";
      echo "<td align='right'>".$value["cex78"]["high"]."</td>";
      echo "<td align='right'>".$value["cex78"]["volume"]."</td>";
      echo "</tr>";
      $num++;
    }
    if (array_key_exists("crx", $value) && (!array_key_exists("e", $_REQUEST) || $_REQUEST['e'] == "crx")) {
      echo "<tr>";
      if ($num == 0) {
        echo "<td rowspan=".(array_key_exists("e", $_REQUEST) ? 1 : count($value))." valign='top'>".makelink($key)."</td>";
      }
      echo "<td>".exchangelink("crx")."</td>";
      echo "<td align='right'>".$value["crx"]["price"]."</td>";
      echo "<td align='right'>".$value["crx"]["low"]."</td>";
      echo "<td align='right'>".$value["crx"]["high"]."</td>";
      echo "<td align='right'>".$value["crx"]["volume"]."</td>";
      echo "</tr>";
    }
  }
  echo "</tbody>
        </table>
        </div>";
  echo "<br /><a href='?'>Home</a> ";
  if (array_key_exists("c", $_REQUEST) && preg_match('/^[0-9a-zA-Z]{2,5}$/', $_REQUEST['c']) && array_key_exists(strtolower($_REQUEST["c"]), $coins)) {
    echo "&gt; <a href='?c=".$_REQUEST["c"]."'>".strtoupper($_REQUEST["c"])."</a> ";
  }
  if (array_key_exists("m", $_REQUEST) && preg_match('/^[0-9a-zA-Z]{2,5}-[0-9a-zA-Z]{2,5}$/', $_REQUEST['m']) && array_key_exists(strtolower($_REQUEST["m"]), $markets)) {
    echo "&gt; <a href='?m=".$_REQUEST["m"]."'>".strtoupper($_REQUEST["m"])."</a> ";
  }
  if (array_key_exists("e", $_REQUEST) && array_key_exists(strtolower($_REQUEST["e"]), $exchanges)) {
    echo "&gt; <a href='?e=".$_REQUEST["e"]."'>".exchangename($_REQUEST["e"])."</a> ";
  }
  echo "</body>
        </html>";
}
?>
