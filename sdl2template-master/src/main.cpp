#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


#ifdef _WIN32 // compiling on windows
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#else // NOT compiling on windows
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#include "audio.h"
#include "sprite.h"

std::string exeName;
SDL_Window *win; //pointer to the SDL_Window
SDL_Renderer *ren; //pointer to the SDL_Renderer
SDL_Surface *surface; //pointer to the SDL_Surface
SDL_Texture *tex; //pointer to the SDL_Texture

// Main Menu :: Chuckie Egg Text
SDL_Surface *messageSurface; //pointer to the SDL_Surface for message
SDL_Texture *messageTexture; //pointer to the SDL_Texture for message
SDL_Rect message_rect; //SDL_rect for the message

// Main Menu :: Play Game Text
SDL_Surface *messageSurface2; //pointer to the SDL_Surface for message2 (Play Game)
SDL_Surface *messageSurface2Select; //pointer to the SDL_Surface for message2 (Play Game) when it is selected
SDL_Texture *messageTexture2; //pointer to the SDL_Texture for message2 (Play Game)
SDL_Rect message_rect2; //SDL_rect for the message2 (Play Game)

// Main Menu :: Options Text
SDL_Surface *messageSurface3; //pointer to the SDL_Surface for message3 (Options)
SDL_Surface *messageSurface3Select; //pointer to the SDL_Surface for message3 (Options) when it is selected
SDL_Texture *messageTexture3; //pointer to the SDL_Texture for message3 (Options)
SDL_Rect message_rect3; //SDL_rect for the message3 (Options)

// Options Menu :: Option Text
SDL_Surface *messageSurface4; //pointer to the SDL_Surface for message4 (Options)
SDL_Texture *messageTexture4; //pointer to the SDL_Texture for message4 (Options)
SDL_Rect message_rect4; //SDL_rect for the message4 ()

// Options Menu :: Window Size Text
SDL_Surface *messageSurface5; //pointer to the SDL_Surface for message5 (Window Size)
SDL_Surface *messageSurface5Select; //pointer to the SDL_Surface for message5 (Window Size) when it is selected
SDL_Texture *messageTexture5; //pointer to the SDL_Texture for message5 (Window Size)
SDL_Rect message_rect5; //SDL_rect for the message5 (Window Size)

// Options Menu :: Volume Text
SDL_Surface *messageSurface6; //pointer to the SDL_Surface for message6 (Volume)
SDL_Surface *messageSurface6Select; //pointer to the SDL_Surface for message6 (Volume) when it is selected
SDL_Texture *messageTexture6; //pointer to the SDL_Texture for message6 (Volume)
SDL_Rect message_rect6; //SDL_rect for the message6 (Volume)

// Options Menu :: Return to Main Menu Text
SDL_Surface *messageSurface7; //pointer to the SDL_Surface for message7 (Window Size)
SDL_Surface *messageSurface7Select; //pointer to the SDL_Surface for message7 (Window Size) when it is selected
SDL_Texture *messageTexture7; //pointer to the SDL_Texture for message7 (Window Size)
SDL_Rect message_rect7; //SDL_rect for the message7 (Window Size)


std::string outputText = "Chuckie Egg"; //Output string for the title
std::string outputText2 = "Play Game"; //Ouput string for the 'Play Game' menu option
std::string outputText3 = "Options"; //Ouput string for the 'Options' menu option

std::string optionText = "Options";
std::string optionText2 = "Window Size: 1280x720";
std::string optionText3 = "Volume: 100%";
std::string optionText4 = "Return to Main Menu";

int menuItemSelect = 1; // 1 == Play Game, 2 == Options
int optionMenuItemSelect = 1; // 1 == Window Size, 2 == Volume, 3 == Return to Main Menu
int gameSceneSelect = 0; // 0 == Main Menu, 1 == Play Game, 2 == Options

unsigned int lastTime = 0, currentTime;
int stretchVAR = 200;


// Music that will be played
Mix_Music *gMusic = NULL;

//SFX that will be used
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;

bool done = false;

Audio audTest;

void handleInput()
{
	//Event-based input handling
	//The underlying OS is event-based, so **each** key-up or key-down (for example)
	//generates an event.
	//  - https://wiki.libsdl.org/SDL_PollEvent
	//In some scenarios we want to catch **ALL** the events, not just to present state
	//  - for instance, if taking keyboard input the user might key-down two keys during a frame
	//    - we want to catch based, and know the order
	//  - or the user might key-down and key-up the same within a frame, and we still want something to happen (e.g. jump)
	//  - the alternative is to Poll the current state with SDL_GetKeyboardState

	SDL_Event event; //somewhere to store an event

	//NOTE: there may be multiple events per frame
	while (SDL_PollEvent(&event)) //loop until SDL_PollEvent returns 0 (meaning no more events)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			done = true; //set donecreate remote branch flag if SDL wants to quit (i.e. if the OS has triggered a close event,
							//  - such as window close, or SIGINT
			break;

			//keydown handling - we should to the opposite on key-up for direction controls (generally)
		case SDL_KEYDOWN:
			//Keydown can fire repeatable if key-repeat is on.
			//  - the repeat flag is set on the keyboard event, if this is a repeat event
			//  - in our case, we're going to ignore repeat events
			//  - https://wiki.libsdl.org/SDL_KeyboardEvent
			if (!event.key.repeat)
				switch (event.key.keysym.sym)
				{
					//hit escape to exit
					case SDLK_ESCAPE: 
						done = true;
						break;


					/* Start of code for handling user input and testing audio stuff


					// Press the 't' key to start playing music
					case SDLK_t:
						if (Mix_PlayingMusic() == 0)
						{
							Mix_PlayMusic(gMusic, -1);
						}
						break;

					// Press the 'y' to pause the music (if already playing) and resume music (is currently paused)
                    case SDLK_y:
						if (Mix_PlayingMusic() == 1)
						{

							if (Mix_PausedMusic() == 0)
							{
								Mix_PauseMusic();
							}
							else
							{
								Mix_ResumeMusic();
							}
							
						}
						break;


					// Press the 'b' key to play the sound effect of the 'gHigh' chunk
					case SDLK_b:
						Mix_PlayChannel(-1, gHigh, -1);
						break;

					// Press the 'n' key to change the volume of the 'gHigh' chunck to be 12
					case SDLK_n:
						Mix_VolumeChunk(gHigh, 12);
						break;

					// Press the 'm' key to change the volume of the 'gHigh' chunck to be 128
					case SDLK_m:
						Mix_VolumeChunk(gHigh, 128);
						break;

					// Press the 'f' key to play the 'gHigh' chunk on repeat with a fade in of 1500 ms
					case SDLK_f:
						Mix_FadeInChannel(-1, gHigh, -1, 1500);
						break;

					// Press the 'd' key to fade out the next occupied channel over 1500 ms
					case SDLK_d:
						Mix_FadeOutChannel(-1, 1500);
						break;

					End of code regarding user input and audio stuff */ 


					case SDLK_s:
						if (gameSceneSelect == 0)
						{
							menuItemSelect = 2;
						}
						else if (gameSceneSelect == 1)
						{

						}
						else
						{
							optionMenuItemSelect++;
						}
						
						break;

					case SDLK_w:
						if (gameSceneSelect == 0)
						{
							menuItemSelect = 1;
						}
						else if (gameSceneSelect == 1)
						{

						}
						else
						{
							optionMenuItemSelect--;
						}
						break;


					case SDLK_RETURN:
						gameSceneSelect = menuItemSelect;
						if (gameSceneSelect == 2 && optionMenuItemSelect == 3)
						{
							gameSceneSelect = 0;
							optionMenuItemSelect = 1;
							menuItemSelect = 1;
						}
						audTest.playSound(gHigh);
						break;

					// Testing for changing the window's size
					case SDLK_t:
						SDL_SetWindowSize(win, 1024, 576);
						break;


					// Testing for different classes
					case SDLK_r:
						audTest.playSound(gHigh);
						spriteClass();
						break;

				}
			break;
		}
	}
}
// end::handleInput[]

// tag::updateSimulation[]
void updateSimulation(double simLength = 0.02) //update simulation with an amount of time to simulate for (in seconds)
{
  //CHANGE ME
}

void render()
{
		//First clear the renderer
		SDL_RenderClear(ren);

		//Draw the texture (Background)
		//SDL_RenderCopy(ren, tex, NULL, NULL);

		switch (gameSceneSelect)
		{

		// Main Menu
		case 0:
		{
			// Rendering stuff for message 1 (Chuckie Egg)

			messageTexture = SDL_CreateTextureFromSurface(ren, messageSurface);
			message_rect.x = 0;
			message_rect.y = 0;
			message_rect.w = 600 + stretchVAR;
			message_rect.h = 200;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture, NULL, &message_rect);


			// Rendering stuff for message 2 (Play Game)

			if (menuItemSelect == 1)
			{
				messageTexture2 = SDL_CreateTextureFromSurface(ren, messageSurface2Select);
			}
			else
			{
				messageTexture2 = SDL_CreateTextureFromSurface(ren, messageSurface2);
			}
			message_rect2.x = 0;
			message_rect2.y = 300;
			message_rect2.w = 300 + stretchVAR;
			message_rect2.h = 150;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture2, NULL, &message_rect2);


			// Rendering stuff for message 3 (Options)


			if (menuItemSelect == 2)
			{
				messageTexture3 = SDL_CreateTextureFromSurface(ren, messageSurface3Select);
			}
			else
			{
				messageTexture3 = SDL_CreateTextureFromSurface(ren, messageSurface3);
			}
			message_rect3.x = 0;
			message_rect3.y = 500;
			message_rect3.w = 300 + stretchVAR;
			message_rect3.h = 150;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture3, NULL, &message_rect3);
		}
		break;

		// Game
		case 1:
		{
			std::cout << "Play Game Scene Frame!";
		}
		break;

		// Options
		case 2:
		{
			messageTexture4 = SDL_CreateTextureFromSurface(ren, messageSurface4);
			message_rect4.x = 0;
			message_rect4.y = 0;
			message_rect4.w = 600 + stretchVAR;
			message_rect4.h = 200;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture4, NULL, &message_rect4);

			// Rendering stuff for message 5 (Resolution)

			if (optionMenuItemSelect == 1)
			{
				messageTexture5 = SDL_CreateTextureFromSurface(ren, messageSurface5Select);
			}
			else
			{
				messageTexture5 = SDL_CreateTextureFromSurface(ren, messageSurface5);
			}
			message_rect5.x = 0;
			message_rect5.y = 200;
			message_rect5.w = 200 + stretchVAR;
			message_rect5.h = 100;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture5, NULL, &message_rect5);


			// Rendering stuff for message 6 (Volume)


			if (optionMenuItemSelect == 2)
			{
				messageTexture6 = SDL_CreateTextureFromSurface(ren, messageSurface6Select);
			}
			else
			{
				messageTexture6 = SDL_CreateTextureFromSurface(ren, messageSurface6);
			}
			message_rect6.x = 0;
			message_rect6.y = 300;
			message_rect6.w = 200 + stretchVAR;
			message_rect6.h = 100;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture6, NULL, &message_rect6);


			// Rendering stuff for message 7 (Exit to Main Menu)


			if (optionMenuItemSelect == 3)
			{
				messageTexture7 = SDL_CreateTextureFromSurface(ren, messageSurface7Select);
			}
			else
			{
				messageTexture7 = SDL_CreateTextureFromSurface(ren, messageSurface7);
			}
			message_rect7.x = 0;
			message_rect7.y = 500;
			message_rect7.w = 300 + stretchVAR;
			message_rect7.h = 150;

			//Draw the text
			SDL_RenderCopy(ren, messageTexture7, NULL, &message_rect7);

		}
		break;


		default:
			break;
		}



		//Update the screen
		SDL_RenderPresent(ren);
}





void cleanExit(int returnValue)
{
	if (messageTexture != nullptr) SDL_DestroyTexture(messageTexture);
	if (tex != nullptr) SDL_DestroyTexture(tex);
	if (ren != nullptr) SDL_DestroyRenderer(ren);
	if (win != nullptr) SDL_DestroyWindow(win);
	// SDL_mixer start
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
	// SDL_mixer end
	SDL_Quit();
	exit(returnValue);
}

// based on http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-1-hello-world/
int main( int argc, char* args[] )
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		cleanExit(1);
	}
	std::cout << "SDL initialised OK!\n";

	//create window
	win = SDL_CreateWindow("SDL Hello World!", 100, 100, 1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);


	//error handling
	if (win == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		cleanExit(1);
	}
	std::cout << "SDL CreatedWindow OK!\n";

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		cleanExit(1);
	}

	std::string imagePath = "./assets/BraveSec1.jpg";
	surface = IMG_Load(imagePath.c_str());
	if (surface == nullptr){
		std::cout << "SDL IMG_Load Error: " << SDL_GetError() << std::endl;
		cleanExit(1);
	}

	tex = SDL_CreateTextureFromSurface(ren, surface);
	SDL_FreeSurface(surface);
	if (tex == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		cleanExit(1);
	}


	if( TTF_Init() == -1 )
	{
		std::cout << "TTF_Init Failed: " << TTF_GetError() << std::endl;
		cleanExit(1);
	}

	TTF_Font* sans = TTF_OpenFont("./assets/angerpoise lampshade.ttf", 102);
	if (sans == nullptr)
	{
		std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
		cleanExit(1);
	}
	SDL_Color White = {255, 255, 255};
	SDL_Color Yellow = { 255, 255, 0 };
	// Messages for the Main Menu
	messageSurface = TTF_RenderText_Solid(sans, outputText.c_str(), White); // Title 'Chuckie Egg' for the Main Menu
	messageSurface2 = TTF_RenderText_Solid(sans, outputText2.c_str(), White); // Surface for when the 'Play Game' option when it's not selected
	messageSurface2Select = TTF_RenderText_Solid(sans, outputText2.c_str(), Yellow); // Surface for when the 'Play Game' option is selected in the menu
	messageSurface3 = TTF_RenderText_Solid(sans, outputText3.c_str(), White); // Surface for when the 'Options' option when it's not selected
	messageSurface3Select = TTF_RenderText_Solid(sans, outputText3.c_str(), Yellow); // Surface for when the 'Options' option is selected in the menu

	// Messages for the Options Menu
	messageSurface4 = TTF_RenderText_Solid(sans, optionText.c_str(), White);
	messageSurface5 = TTF_RenderText_Solid(sans, optionText2.c_str(), White); // Surface for when the 'Window Size' option when it's not selected
	messageSurface5Select = TTF_RenderText_Solid(sans, optionText2.c_str(), Yellow); // Surface for when the 'Window Size' option is selected in the menu
	messageSurface6 = TTF_RenderText_Solid(sans, optionText3.c_str(), White); // Surface for when the 'Volume' option when it's not selected
	messageSurface6Select = TTF_RenderText_Solid(sans, optionText3.c_str(), Yellow); // Surface for when the 'Volume' option is selected in the menu
	messageSurface7 = TTF_RenderText_Solid(sans, optionText4.c_str(), White); // Surface for when the 'Back to Main Menu' option when it's not selected
	messageSurface7Select = TTF_RenderText_Solid(sans, optionText4.c_str(), Yellow); // Surface for when the 'Back to Main Menu' option is selected in the menu



	// error handling for audio
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialise. SDL_mixer Error: %s\n", Mix_GetError());
		cleanExit(1);
	}

	gMusic = Mix_LoadMUS("./assets/musicSFX/beat.wav");
	if (!gMusic)
	{
		printf("Gone done goofed on gMusic");
		//ERROR
	}

	gHigh = Mix_LoadWAV("./assets/musicSFX/high.wav");
	if(!gHigh)
	{
		printf("Loading the High wav has failed"); //Error message in-case the loading in of the 'High' wav file fails
	}




	while (!done) //loop until done flag is set)
	{
		handleInput(); // this should ONLY SET VARIABLES

		updateSimulation(); // this should ONLY SET VARIABLES according to simulation

		//currentTime = SDL_GetTicks();
		//auto t1 = Clock::now();

		render(); // this should render the world state according to VARIABLES

		//render2();

		//lastTime = SDL_GetTicks();
		//auto t2 = Clock::now();
		//std::cout << "Delta t2-t1: "
		//	<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
		//	<< " nanoseconds" << std::endl;

		//currentTime = lastTime - currentTime;
		//std::cout << currentTime << std::endl;

		SDL_Delay(20); // unless vsync is on??
	}

	cleanExit(0);
	return 0;
}
