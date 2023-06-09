<?php


namespace App;


class MostLetterSetence
{
    /*Write a program that reads in a string and determines the letter that occurs the most.
        const input = "Random words in front of other random words create a random sentence.";*/

    public function __construct($sentence)
    {
        $this->MostLetters($sentence);
    }

    public function MostLetters(string $sentence)
    {
        $newSentence = str_split($sentence);
        $test = [];
        $la = 0;
        foreach ($newSentence as $key => $value) {
            $test[$key]['amount'] = $value;

        }

        print_r($la);
    }

}
