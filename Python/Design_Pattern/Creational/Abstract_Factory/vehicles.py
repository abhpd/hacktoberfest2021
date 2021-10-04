from abc import ABC, abstractmethod


class AbstractTwoWheelsVehicle(ABC):

    @abstractmethod
    def get_weight_of_the_vehicle(self) -> float:
        """ get the weight in kilogram"""
        pass


class BicycleVehicle(AbstractTwoWheelsVehicle):
    def get_weight_of_the_vehicle(self) -> float:
        return 12.2


class MotorCycleVehicle(AbstractTwoWheelsVehicle):
    def get_weight_of_the_vehicle(self) -> float:
        return 143.1


class AbstractFourWheelsVehicle(ABC):

    @abstractmethod
    def get_weight_of_the_vehicle(self) -> float:
        """ get the weight in kilogram"""
        pass


class PedalCarVehicle(AbstractTwoWheelsVehicle):
    def get_weight_of_the_vehicle(self) -> float:
        return 18.2


class CarVehicle(AbstractTwoWheelsVehicle):
    def get_weight_of_the_vehicle(self) -> float:
        return 1143.1