struct Card 
{
    char rank;  // достоинство
    char suit;  // масть
};

int check(struct Card * hand)
{
    struct Card * p;
    
    for(p = hand; p->rank != 0; p++)
    {
        if(p->rank == 'Q')
            break;
    }
    if(p->rank == 0)
        return 0;

    for(p = hand; p->suit != 0; p++)
    {
        if(p->suit == 's')
            return 1;
    }

    return 0;
}
