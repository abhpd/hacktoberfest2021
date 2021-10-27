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

$result = bubble_sort([1, 10, 2, 4, 5, 1, 2, 3]);

print_r($result);
