#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

double Rand_Y() {
  int tab[2]={1,-1};
  return (float)(rand()%75*tab[rand()%2])/10.0;
}


const int HEIGHT = 1300;
const int WIDTH = 2400;
const int RADIUS = 20;

const double speed = 0.125;
int PlayerScore = 0;
int EnemyScore = 0;
sf::RectangleShape player;
sf::RectangleShape enemy;
sf::RectangleShape line;
sf::CircleShape ball;
bool gameStart = false;

int main(){
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong!",sf::Style::Titlebar | sf::Style::Close);
  player.setSize(sf::Vector2f(50, 200));
  enemy.setSize(sf::Vector2f(50, 200));
  line.setSize(sf::Vector2f(20,HEIGHT));

  sf::Font font;
  font.loadFromFile("Font.ttf");

  sf::Vector2f PlayerV(0.0f,0.0f);
  sf::Vector2f EnemyV(0.0f,0.0f);
  sf::Vector2f Ball(0.0f,0.0f);
  sf::Vector2f PlayerPos;
  sf::Vector2f EnemyPos;
  sf::Vector2f BallPos;
  sf::Text Score1;
  sf::Text Score2;
  Score1.setFont(font);
  Score2.setFont(font);
  Score1.setCharacterSize(200);
  Score2.setCharacterSize(200);
  Score1.setFillColor(sf::Color::White);
  Score2.setFillColor(sf::Color::White);
  ball.setRadius(RADIUS);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(WIDTH/2-RADIUS,HEIGHT/2-RADIUS);
  Score1.setPosition(WIDTH/2+100,0);
  Score2.setPosition(WIDTH/2-200,0);
  sf::Clock clock;

  player.setFillColor(sf::Color::White);
  enemy.setFillColor(sf::Color::White);
  line.setFillColor(sf::Color::White);

  enemy.setPosition(20,HEIGHT/2-50);
  player.setPosition(WIDTH-70,HEIGHT/2-50);
  line.setPosition(WIDTH/2-10,0);
  window.setFramerateLimit(200);

  while (window.isOpen()) {
    float wsp = 1.0;
    PlayerPos=player.getPosition();
    EnemyPos=enemy.getPosition();
    BallPos=ball.getPosition();
    if(gameStart&&Ball.x==0.0f){
      Ball.x=11.0f;
      Ball.y=Rand_Y();
    }
    PlayerV.y=0.0f;
    EnemyV.y = 0.0f;
    sf::Time time = clock.restart();
    int sec = time.asMilliseconds();

    sf::Event evnt;
    while (window.pollEvent(evnt))
    {
        switch (evnt.type) {
          case sf::Event::Closed:
            window.close();
            break;
        }
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&player.getPosition().y>10){
      PlayerV.y=-10.0*speed*sec;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&player.getPosition().y<HEIGHT-210){
      PlayerV.y=10.0*speed*sec;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
      gameStart=true;
    }
    if(EnemyPos.y>BallPos.y&&BallPos.x<WIDTH/2-300){
      EnemyV.y=-10.0*speed*sec;
    }
    else if(EnemyPos.y+200<BallPos.y&&BallPos.x<WIDTH/2-300){
      EnemyV.y=10.0*speed*sec;
    }

    if(ball.getPosition().x+Ball.x>WIDTH-2*RADIUS){
      Ball.x=0.0f;
      Ball.y=0.0f;
      gameStart=false;
      ball.setPosition(WIDTH/2-RADIUS,HEIGHT/2-RADIUS);
      EnemyScore++;
    }
    if(ball.getPosition().y+Ball.y>HEIGHT-2*RADIUS){
      Ball.y*=-1;
    }
    if(ball.getPosition().x+Ball.x<0){
      Ball.x=0.0f;
      Ball.y=0.0f;
      gameStart=false;
      ball.setPosition(WIDTH/2-RADIUS,HEIGHT/2-RADIUS);
      PlayerScore++;
    }
    if(ball.getPosition().y+Ball.y<0){
      Ball.y*=-1;
    }
    if(BallPos.x+Ball.x*speed*sec>PlayerPos.x-50&&BallPos.y+2*RADIUS-10>PlayerPos.y-10&&BallPos.y<PlayerPos.y+200){

      Ball.x*=-1;
      Ball.y+=PlayerV.y*0.2;
    }
    if(BallPos.x+Ball.x*speed*sec<EnemyPos.x+50&&BallPos.y+2*RADIUS-10>EnemyPos.y-10&&BallPos.y<EnemyPos.y+200){
      Ball.x*=-1;
    }

    Score1.setString(std::to_string(PlayerScore));
    Score2.setString(std::to_string(EnemyScore));
    player.move(PlayerV);
    enemy.move(EnemyV);
    ball.move(Ball.x*speed*sec,Ball.y*speed*sec);
    window.clear();
    window.draw(player);
    window.draw(enemy);
    window.draw(ball);
    window.draw(Score1);
    window.draw(Score2);
    window.draw(line);
    window.display();

  }
}
