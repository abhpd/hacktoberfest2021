<?php

function bubble_sort($array)
{
    $length = count($array);

    if (!$length) {
        return $array;
    }

    for ($i = 0; $i < $length; $i++) {
        for ($j = 0; $j < $length; $j++) {
            if ($array[$i] < $array[$j]) {
                $tmp = $array[$i];
                $array[$i] = $array[$j];
                $array[$j] = $tmp;
            }
        }
    }

    return $array;
}

$result = bubble_sort([3, 1, 10, 2, 1, 7, 0, 4, 8, 6, 5, 9]);

print_r($result);
