//Two fighters, one winner.
bool isDead(Fighter* fighter)
{
    return fighter->getHealth() <= 0;
}

void hitDefender(Fighter* defender, int attackDamage)
{
    int newHealth = defender->getHealth() - attackDamage;
    defender->setHealth(newHealth);
}

std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
    // Your code goes here. Have fun!
    std::vector<Fighter*> combatants = {fighter1, fighter2};

    int attackingCombatant = firstAttacker.compare(combatants[0]->getName()) == 0 ? 0 : 1;
    int defendingCombatant = -1;
    Fighter* attacker = NULL;
    do
    {
        attacker = combatants[attackingCombatant];
        defendingCombatant = (attackingCombatant + 1) % 2;
        Fighter* defender = combatants[defendingCombatant];

        hitDefender(defender, attacker->getDamagePerAttack());

        attackingCombatant = defendingCombatant;
    } while (!isDead(combatants[defendingCombatant]));

    return attacker->getName();
}