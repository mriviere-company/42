#!/usr/bin/php
<?php
if ($argc > 1)
{
  $init = curl_init();
  curl_setopt($init, CURLOPT_URL, $argv[1]);
  curl_setopt($init, CURLOPT_RETURNTRANSFER, true);
  $tmp = curl_exec($init);
  
  preg_match_all("<img.+src=\"(.+?)\".+>", $tmp, $matches);
  $i = 0;
  $dir = parse_url($argv[1], PHP_URL_HOST);
  mkdir($dir);
  while ($i < count($matches[1]))
  {
    curl_setopt($init, CURLOPT_URL, $matches[1][$i]);
    $tmp = curl_exec($init);
  
    $file = substr($matches[1][$i], strrpos($matches[1][$i], "/") + 1);
    file_put_contents($dir . DIRECTORY_SEPARATOR . $file, $tmp);
    $i++;
  }
  curl_close($init);
}
?>