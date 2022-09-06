// application.hpp

#pragma once

#include "batch.hpp"

namespace runner
{
   class Application final
   {
   public:
      Application() = default;

      void run();

   private:
      bool enter();
      void exit();
      bool update();
      void render();

   private:
      void on_mouse_move(const sf::Vector2f &position);
      void on_key_pressed(const sf::Keyboard::Key key);
      void on_key_released(const sf::Keyboard::Key key);
      void on_button_pressed(const sf::Mouse::Button button);
      void on_button_released(const sf::Mouse::Button button);
      void timer();
      void JumpAnimation();
      void BackgrdControl();

   private:
      sf::RenderWindow m_window;
      PrimitiveBatch   m_batch;
      bool             m_running = true;
      sf::Clock        m_clock;
      sf::Time         m_deltatime;
      sf::Vector2f     m_mouse_position;

      sf::Sprite stand;
      sf::Sprite RunSprite;
      sf::Sprite JumpAniSprite1;
      sf::Sprite JumpAniSprite2;
      sf::Sprite BackgrdSprite;
      sf::Sprite BackgrdSprite2;

      sf::Image StandImage;
      sf::Image RunImage;
      sf::Image JumpAniImage1;
      sf::Image JumpAniImage2;
      sf::Image BackgrdImage;
      sf::Image BackgrdImage2;

      sf::Texture StandTexture;
      sf::Texture RunTexture;
      sf::Texture JumpAniTexture1;
      sf::Texture JumpAniTexture2;
      sf::Texture BackgrdTexture;
      sf::Texture BackgrdTexture2;

      bool standing = true , running = false;

      sf::Clock clock;
      sf::Time time;

      sf::Clock animationClock;
      sf::Time animationTime;
   };
} // !runner
