from patterns.creational.abstract_factory import AbstractVehicleFactory, MotorFactory, EcologicalFactory


def client_order(factory: AbstractVehicleFactory) -> None:
    two_wheels_product = factory.createTwoWheelsVehicle()
    four_wheels_product = factory.createFourWheelsVehicle()

    print(f"{factory.__class__.__name__}: 2 wheels vehicle weight ({two_wheels_product.__class__.__name__}):"
          f" {two_wheels_product.get_weight_of_the_vehicle()} kg")
    print(f"{factory.__class__.__name__}: 4 wheels vehicle weight ({four_wheels_product.__class__.__name__}):"
          f" {four_wheels_product.get_weight_of_the_vehicle()} kg")


if __name__ == "__main__":
    print("Client creates two products with the Motor Factory")
    client_order(MotorFactory())

    print("\n")

    print("Client creates two products with the 'Ecological' Factory")
    client_order(EcologicalFactory())