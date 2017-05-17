#!/usr/bin/php
<?php
if($argc > 1)
{
  $take = @fopen($argv[1], 'r');
    if($take === FALSE)
    {
      echo "Only html file.\n";
      return;
    }
    $string = @fread($take, filesize($argv[1]));
    function upup($tab)
    {
      return strtoupper($tab[0]);
    }
    function upup2($tab)
    {
      $str = preg_replace_callback("/>(.|\n)*</U", "upup", $tab[0]);
      return($str);
    }
    $string = preg_replace_callback("/\".*\"/U", "upup", $string);
    $string = preg_replace_callback("/<a(.|\n)*<\/a>/U", "upup2", $string);
    echo $string;
    @fclose($take);
}
return;
?>