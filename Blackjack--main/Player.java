package blackjack;

public class Player {
    public String name;
    public int score = 0;
    public Card[] arr=new Card[11];
    public int cardCnt = 2;
    public int getScore() {
        return score;
    }

    public String getName() {
        return name;
    }

    public void addCard(Card card){
        if(cardCnt<11){
            arr[cardCnt]=card;
        }
    }
}