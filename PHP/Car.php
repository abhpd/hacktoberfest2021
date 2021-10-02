<?php

class Car {
    public $color;
    public $model;
    public $licensePlate;

    public function __construct($color, $model, $licensePlate)
    {
        $this->color = $color;
        $this->model = $model;
        $this->licensePlate = $licensePlate;
    }

    public function setColor($color)
    {
        $this->color = $color;
    }

    public function setModel($model)
    {
        $this->model = $model;
    }

    public function setLicensePlate($licensePlate)
    {
        $this->licensePlate = $licensePlate;
    }

    public function getColor()
    {
        return $this->color;
    }

    public function getModel()
    {
        return $this->model;
    }

    public function getLicensePlate()
    {
        return $this->licensePlate;
    }
}

$car = new Car('white', 'Tesla Model Y', 'VAR Y');

echo $car->getColor();
echo '<br />';
echo $car->getModel();
echo '<br />';
echo $car->getLicensePlate();