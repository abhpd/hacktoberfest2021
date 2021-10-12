<?php


namespace App;


class DescendingOrder
{
    public function generate(int $number){
        $array_number = str_split($number);
        rsort($array_number);
        return implode($array_number);
    }
}
