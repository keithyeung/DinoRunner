// application.cpp

#include "application.hpp"


namespace runner
{
   
   void Application::run()
   {
      const sf::VideoMode mode{ 1280, 720 };
      const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
      m_window.create(mode, "pineapple", flags);
      if (!m_window.isOpen() || !enter()) {
         return;
      }

      m_window.setKeyRepeatEnabled(false);
      while (m_window.isOpen()) {
         sf::Event event;
         while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::MouseMoved) {
               on_mouse_move({ float(event.mouseMove.x), float(event.mouseMove.y) });
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
               on_button_pressed(event.mouseButton.button);
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
               on_button_released(event.mouseButton.button);
            }
            else if (event.type == sf::Event::KeyPressed) {
               on_key_pressed(event.key.code);
            }
            else if (event.type == sf::Event::Closed) {
               m_window.close();
            }
         }

         if (!update()) {
            m_window.close();
         }

         render();
      }

      exit();
   }

   bool Application::enter()
   {
       m_window.setFramerateLimit(60);
        if (!(StandImage.loadFromFile("assets/AlienSpider.png")))
        {
            __debugbreak();
        }
        
        StandTexture.loadFromImage(StandImage);
        stand.setTexture(StandTexture);
        stand.setScale(0.5, 0.5);



        if (!(RunImage.loadFromFile("assets/AlienSpiderWalking.png")))
        {
            __debugbreak();
        }
        RunTexture.loadFromImage(RunImage);
        RunSprite.setTexture(RunTexture);
        RunSprite.setScale(0.5, 0.5);



        if (!(JumpAniImage1.loadFromFile("assets/JumpAnimate1.png")))
        {
            __debugbreak();
        }
        JumpAniTexture1.loadFromImage(JumpAniImage1);
        JumpAniSprite1.setTexture(JumpAniTexture1);
        JumpAniSprite1.setScale(0.5, 0.5);

        
        
        if (!(JumpAniImage2.loadFromFile("assets/JumpAnimate2.png")))
        {
            __debugbreak();
        }
        JumpAniTexture2.loadFromImage(JumpAniImage2);
        JumpAniSprite2.setTexture(JumpAniTexture2);
        JumpAniSprite2.setScale(0.5, 0.5);
        


        if (!(BackgrdImage.loadFromFile("assets/Backgrd.png")))
        {
            __debugbreak();
        }
        BackgrdTexture.loadFromImage(BackgrdImage);
        BackgrdSprite.setTexture(BackgrdTexture);
        BackgrdSprite.setScale(2, 1.3);
        BackgrdSprite.setPosition(0, 0);
        
        if (!(BackgrdImage2.loadFromFile("assets/Backgrd.png")))
        {
            __debugbreak();
        }
        BackgrdTexture2.loadFromImage(BackgrdImage2);
        BackgrdSprite2.setTexture(BackgrdTexture2);
        BackgrdSprite2.setScale(2, 1.3);
        BackgrdSprite2.setPosition(1280, 0);



        return true;
   }

   void Application::exit()
   {
   }

   bool Application::update()
   {
      m_deltatime = m_clock.restart();
      BackgrdSprite.setPosition(BackgrdSprite.getPosition().x -1, BackgrdSprite.getPosition().y);
      BackgrdSprite2.setPosition(BackgrdSprite2.getPosition().x -1, BackgrdSprite2.getPosition().y);
      BackgrdControl();
      return m_running;
   }

   void Application::render()
   {
       
      m_batch.clear();
      { 
            m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });
         // note: draw a white line from the center of the screen 
         //       to the current mouse position
         sf::Vector2f center_screen{ 640.0f, 360.0f };
         //m_batch.draw_line(center_screen, m_mouse_position, 1.0f, sf::Color::White);

         // note: draw a small green circle around the current 
         //       mouse position
            m_batch.draw_circle(m_mouse_position, 15.0f, 12, 1.0f, sf::Color::Green);
            
            m_window.draw(BackgrdSprite);
            m_window.draw(BackgrdSprite2);

            if (standing)
            {
                m_window.draw(stand);
            }
            else if (running)
            {
                m_window.draw(RunSprite);
            }
            timer();
            
      }
      m_batch.present(m_window);
      m_window.display();
   }

   void Application::on_mouse_move(const sf::Vector2f &position) 
   {
      m_mouse_position = position;
   }

   void Application::on_key_pressed(const sf::Keyboard::Key key)
   {
      if (key == sf::Keyboard::Key::Escape) {
         m_running = false;
      }
      else if (key == sf::Keyboard::Key::Space)
      {
          //JumpAnimation();
      }
   }

   void Application::on_key_released(const sf::Keyboard::Key key)
   {
   }

   void Application::on_button_pressed(const  sf::Mouse::Button button)
   {
   }

   void Application::on_button_released(const sf::Mouse::Button button)
   {
   }
   void Application::timer()
   {
       
       time = clock.getElapsedTime();
       if (time.asMilliseconds() >= 120)
       {
           clock.restart();
           if (standing)
           {
               standing = false;
               running = true;
           }
           else if (running)
           {
               running = false;
               standing = true;
           }
       }
   }
   void Application::JumpAnimation()
   {
       standing = false;
       running = false;
       m_window.draw(JumpAniSprite2);
   }
   void Application::BackgrdControl()
   {
       if (BackgrdSprite.getPosition().x < (-1280))
       {
           BackgrdSprite.setPosition((BackgrdSprite2.getPosition().x+BackgrdSprite2.getTexture()->getSize().x), 0);
       }
       
       if (BackgrdSprite2.getPosition().x < (-1280))
       {
           BackgrdSprite2.setPosition(1280, 0);
       }



   }
} // !runner
