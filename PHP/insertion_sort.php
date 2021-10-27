<?php

function insertion_sort($array) 
{
    $length = count($array);

    for ($i = 1; $i < $length; $i++) {
        $j = $i;
        while ($j >= 1 and $array[$j - 1] > $array[$j]) {
            $tmp = $array[$j];
            $array[$j] = $array[$j - 1];
            $array[$j - 1] = $tmp;
            $j--;
        }
    }

    return $array;
}

$result = insertion_sort([3, 1, 10, 2, 1, 7, 0, 4, 8, 6, 5, 9]);

print_r($result);
