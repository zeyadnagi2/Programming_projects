package blackjack;

import java.util.Random;
import java.util.Scanner;

public class Game {
    public Player[] players = new Player[4];
    public Card[] deck = new Card[52];
    public Card Rand(){
        Random Rand = new Random();
        int Random;
        Card tCard;

        do
        {
            Random = Rand.nextInt();
            tCard = deck[Random] ;
            this.deck[Random]= null ;

        }while(this.deck[Random] == null);
        return tCard;

    }
    public void PlayerInfo (int i){
        Scanner scanner = new Scanner(System.in);
        System.out.println("please enter player name : ");
        players[i].name = scanner.next();
        for (int j = 0 ; j <2 ; j++){
            players[i].arr[j] = new Card(Rand());
        }
    }

    public int update_maximum (){
        int mx = 0 ;
        for(int i=0;i<3;i++){
            if(players[i].getScore()>21)
                continue;
            else if ( mx<players[i].getScore())
                mx = players[i].getScore();
        }
        return mx;
    }

    public void setInfo() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 4; i++) {
            System.out.println("Please Enter name of player" + (i + 1) + " : ");
            players[i] = new Player();
            players[i].name = scanner.next();
            players[i].arr[0] = draw();
            players[i].arr[1] = draw();
            players[i].score+= players[i].arr[0].getValue();
            players[i].score+= players[i].arr[1].getValue();
        }
    }

    public Card draw() {
        Random random = new Random();
        int randomNum;
        Card card ;
        do {
            randomNum = random.nextInt(51);

        } while (deck[randomNum] == null);
        card = deck[randomNum];
        deck[randomNum] = null;
        return card;
    }

    public void generate() {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                int value = (j >= 10) ? 10 : j + 1;
                Card card = new Card(i, j, value);
                deck[cnt] = card;
                cnt++;
            }
        }
    }
}



