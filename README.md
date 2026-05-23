# heroe

This project is a C++ Object-Oriented Programming (OOP) practice.  
It simulates a videogame with a hero who can:

- Join a guild
- Equip a weapon
- Attack using polymorphic behavior
- Use a potion during combat

OOP concepts used

- Classes
- Inheritance
- Composition
- Aggregation
- Polymorphism
- Dependency

## Program Flow

When it starts, the player must choose a guild  
(healing, combat, or trade) from a menu. Once selected, the hero joins the chosen guild  
and receives a confirmation message.

After that, the hero automatically equips a sword called Master Sword, which has a base damage and a sharpness value.

The hero can also use a potion to recover health.

Finally, the hero can perform an attack:

- If a weapon is equipped, the attack() method of the corresponding class  
  (in this case, the sword) is called, displaying a message with the damage dealt.
- If no weapon were equipped, a warning message would be shown indicating that the hero cannot attack.

## Object-Oriented Design

Class relationships:

- The Hero inherits from GameObject (inheritance)
- The Hero owns Stats and SoulMark (composition)
- The Hero is associated with a Guild (aggregation)
- The Hero equips a Weapon through a base-class pointer (aggregation + polymorphism)
- A Potion is passed to the Hero and used instantly (dependency)
