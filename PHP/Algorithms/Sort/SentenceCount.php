<?php


namespace App;


class SentenceCount
{

    public function count(string $sentence){
        $string = str_replace(' ','', $sentence);//remove the white spaces so it doesn't count as a character
        $letterTotal = array_count_values( str_split( $string) ); //counts the array using the value of their keys
        arsort( $letterTotal ); //sorts in reverse order big => small


        return array_keys( $letterTotal )[0]; //get's the first index as the numbers are sorted big => small

    }
}
