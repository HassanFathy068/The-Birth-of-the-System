import random

class Villain:
    def __init__(self, name, health=100, energy=500):
        self.name = name
        self.health = health
        self.energy = energy

    def attack(self, opponent):
        pass

    def take_damage(self, damage):
        self.health -= damage

    def is_defeated(self):
        return self.health <= 0


class Gru(Villain):
    def attack(self, opponent):
        weapons = [     
            {"name": "Freeze Gun", "energy": 50, "damage": 11},
            {"name": "Electric Prod", "energy": 88, "damage": 18},
            {"name": "Mega Magnet", "energy": 92, "damage": 10},
            {"name": "Kalman Missile", "energy": 120, "damage": 20}
        ]
        weapon = random.choice(weapons)
        if self.energy >= weapon["energy"]:
            self.energy -= weapon["energy"]
            opponent.take_damage(weapon["damage"])


class Vector(Villain):
    def attack(self, opponent):
        weapons = [
            {"name": "Laser Blasters", "energy": 40, "damage": 8},
            {"name": "Plasma Grenades", "energy": 56, "damage": 13},
            {"name": "Sonic Resonance Cannon", "energy": 100, "damage": 22}
        ]
        weapon = random.choice(weapons)
        if self.energy >= weapon["energy"]:
            self.energy -= weapon["energy"]
            opponent.take_damage(weapon["damage"])


def simulate_game():
    gru = Gru("Gru")
    vector = Vector("Vector")

    round_count = 1
    while True:
        print(f"Round {round_count}")
        print(f"{gru.name}: Health={gru.health}, Energy={gru.energy}")
        print(f"{vector.name}: Health={vector.health}, Energy={vector.energy}")

        gru.attack(vector)
        if vector.is_defeated():
            print(f"{vector.name} has been defeated. {gru.name} wins!")
            break

        vector.attack(gru)
        if gru.is_defeated():
            print(f"{gru.name} has been defeated. {vector.name} wins!")
            break

        round_count += 1


simulate_game()