#include "card.h"
#include "string.h"
#include <stdlib.h>
#include <ctype.h>

void getcard(ST_cardData_t *cardData)
{
    strcpy(cardData->cardHolderName,"");
    strcpy(cardData->primaryAccountNumber,"");
    strcpy(cardData->cardExpirationDate,"");
}
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    if(cardData==NULL)
    {
        return WRONG_NAME;
    }
    printf("Enter card holder name  : ");
    uint8_t holdername[25];
    gets(holdername);
    int l=strlen(holdername);
    if(l<20||l>24)
    {
        return WRONG_NAME;
    }
    strcpy(cardData->cardHolderName,holdername);
    printf("\n");
    return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    if(cardData==NULL)
    {
        return WRONG_EXP_DATE;
    }
    uint8_t carddate[6];
    printf("Enter card date 'MM/YY'   : ");
    gets(carddate);

    int l=strlen(carddate);
    if(l!=5)
    {
        return WRONG_EXP_DATE;
    }
    if(!isdigit(carddate[0]) || !isdigit(carddate[1]) || carddate[2]!='/' || !isdigit(carddate[3]) || !isdigit(carddate[4]))
    {
        return WRONG_EXP_DATE;
    }
    strcpy(cardData->cardExpirationDate,carddate);
    printf("\n");
    return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    if(cardData==NULL)
    {
        return WRONG_PAN;
    }
    uint8_t cardnumb[20];
    printf("Enter primary card number   : ");
    gets(cardnumb);
    int l=strlen(cardnumb);
    if(l<16||l>19)
    {
        return WRONG_PAN;
    }
    for(int i=0;i<l;i++)
    {
        if(!isdigit(cardnumb[i]))
        {
            return WRONG_PAN;
        }
    }
    strcpy(cardData->primaryAccountNumber,cardnumb);
    return CARD_OK;

}


