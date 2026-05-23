# heroe
This project is a C++ Object-Oriented Programming (00P) practice. Ir simulates a videogame with a hero who can:
- Join a guild
- Equip a weapon
- Attack using polymorphic behavior

OOP concepts use:
- Classes
- Inheritance
- Composition
- Aggregation
- Polymorphism
#Program Flow
When it starts, the player must choose a guild (healing, combat, or trade) from a menu. Once selected, the hero joins the chosen guild and receives a confirmation message.
  After that, the hero automatically equips a sword called Master Sword, which has a defined damage value.  
Finally, the hero can perform an attack:

- If a weapon is equipped, the `attack()` method of the corresponding class (in this case, the sword) is called, displaying a message with the damage dealt.
- If no weapon were equipped, a warning message would be shown indicating that the hero cannot attack.
#Object-Oriented Design
Classes relationship:
 The hero is associated with a guild (aggregation)
- The hero equips a weapon (composition)
- Polymorphism is used to execute the attack
