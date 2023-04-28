package blackjack;

import java.util.Scanner;

public class BlackJack {
    public static void main(String[] args) {
        GUI gui = new GUI();
        Scanner input = new Scanner(System.in);
        Game game = new Game();
        game.generate();
        game.setInfo();
        gui.runGUI(game.deck,
                game.players[0].arr
                , game.players[1].arr
                , game.players[2].arr
                , game.players[3].arr);
        for (int i = 0; i < 3; i++) {
            for (int j = 2; j < 11; j++) {
                char checkInput = input.next().charAt(0);
                System.out.println("enter 1 to draw a card : ");
                if (checkInput == '1') {
                    game.players[i].arr[game.players[i].cardCnt] = game.draw();
                    game.players[i].score += game.players[i].arr[game.players[i].cardCnt].getValue();
                    System.out.println("score player this " + game.players[i].score);
                    gui.updatePlayerHand(game.players[i].arr[game.players[i].cardCnt], i);
                    game.players[i].cardCnt++;
                    if (game.players[i].score > 21)
                        break;
                } else
                    break;
            }
        }

        int max = 0 , max_index = 0;
        boolean push = false;
        int checkPlayer = 0;
        for(int i = 0;i < 3;i++)
        {
            if (game.players[3].score <= game.players[i].score && game.players[i].score <= 21 )
                checkPlayer++ ;
            if (max < game.players[i].score && game.players[i].score <=21) {
                max = game.players[i].score;
                max_index =i;
            }
        }
        for(int i=0;i<3;i++){
            if(max==game.players[i].score && i != max_index)
                push = true;
        }
    if (checkPlayer == 0 )
        System.out.println("|---------------Delaer Wins---------------|");
    else {
        while (game.players[3].score <= max) {
            game.players[3].arr[game.players[3].cardCnt] = game.draw();
            game.players[3].score += game.players[3].arr[game.players[3].cardCnt].getValue();
            System.out.println("Score player this is  " + game.players[3].score);
            gui.updateDealerHand(game.players[3].arr[game.players[3].cardCnt], game.deck);
            game.players[3].cardCnt++;
        }
        if (game.players[3].score <= 21)
            System.out.println("|---------------Delaer Wins---------------|");
        else if(push)
            System.out.println("----------------- Push -----------------");
        else
            System.out.println("|--------player " + game.players[max_index].name + " wins-------|");
    }
    }
}