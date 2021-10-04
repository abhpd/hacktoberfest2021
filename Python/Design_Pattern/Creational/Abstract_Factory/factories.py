from abc import ABC, abstractmethod

from patterns.creational.abstract_factory import (
    AbstractTwoWheelsVehicle, AbstractFourWheelsVehicle, MotorCycleVehicle, CarVehicle, PedalCarVehicle, BicycleVehicle
)


class AbstractVehicleFactory(ABC):

    @abstractmethod
    def createTwoWheelsVehicle(self) -> AbstractTwoWheelsVehicle:
        pass

    @abstractmethod
    def createFourWheelsVehicle(self) -> AbstractFourWheelsVehicle:
        pass


class MotorFactory(AbstractVehicleFactory):

    def createTwoWheelsVehicle(self) -> AbstractTwoWheelsVehicle:
        return MotorCycleVehicle()

    def createFourWheelsVehicle(self) -> AbstractFourWheelsVehicle:
        return CarVehicle()


class EcologicalFactory(AbstractVehicleFactory):

    def createTwoWheelsVehicle(self) -> AbstractTwoWheelsVehicle:
        return BicycleVehicle()

    def createFourWheelsVehicle(self) -> AbstractFourWheelsVehicle:
        return PedalCarVehicle()