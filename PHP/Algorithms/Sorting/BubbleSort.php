<?php

function bubble_sort($arr) {
    $length = count($arr)-1;
    
    for ($i=0; $i < $length; $i++) {
        for ($j=0; $j < $length-$i; $j++) {
            $k = $j+1;
            if ($arr[$k] < $arr[$j]) {
                list($arr[$j], $arr[$k]) = array($arr[$k], $arr[$j]);
            }
        }
    }

    return $arr;
}