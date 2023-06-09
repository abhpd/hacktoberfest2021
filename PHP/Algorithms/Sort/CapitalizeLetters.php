<?php


namespace App;


class CapitalizeLetters
{
    public function toJadenCase(string $word):string
    {
        return ucwords($word);
    }
}
