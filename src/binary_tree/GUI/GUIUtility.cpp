#include "GUIUtility.h"

int GUI::LoadAllegro()
{
	
	if(!al_init())
	{
	
		
		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro Liblary Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro Liblary Sucessfull..." << std::endl;
	}

	if (!al_init_primitives_addon())
	{


		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro Primitives Addon Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro Primitives Addon Sucessfull..." << std::endl;
	}


	if (!al_init_font_addon())
	{


		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro Font Addon Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro Font Addon Sucessfull..." << std::endl;
	}


	if (!al_init_ttf_addon())
	{


		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro TTF Addon Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro TTF Addon Sucessfull..." << std::endl;
	}

	if(!al_install_audio())
	{


		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro AUDIO Addon Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro AUDIO Addon Sucessfull..." << std::endl;
	}

	if (!al_init_acodec_addon())
	{


		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro ACODED Addon Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro ACODEC Addon Sucessfull..." << std::endl;
	}

	if (!al_reserve_samples(1))
	{


		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro SAMPLE Addon Failed!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro SAMPLE Addon Sucessfull..." << std::endl;
	}





	
	setConsoleColor(MessageType::T_NORMAL);
	return 1;
}

void GUI::setConsoleColor(MessageType t)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(t)
	{
	case MessageType::T_ERROR:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 0);
		break;
	case MessageType::T_INFO:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | 0);
		break;
	case MessageType::T_NORMAL:
		SetConsoleTextAttribute(hStdOut, (1 | 2 | 4) | 0);
		break;
	default:
		SetConsoleTextAttribute(hStdOut, (1 | 2 | 4) | 0);

	}
}

void GUI::GUIDisplay::loadDefaultFont()
{
	if(!this->GUIFont)
	{
		this->GUIFont = al_load_ttf_font(this->defaultFontPath.c_str(), this->fontSize, 0);
		if(!this->GUIFont)
		{
			this->GUIFont = al_load_ttf_font(this->defaultRelaseFontPath.c_str(), this->fontSize, 0);
			if(!this->GUIFont)
			{
				setConsoleColor(MessageType::T_ERROR);
				std::cout << "[ERROR]Loading default font failed!" << std::endl;
				setConsoleColor(MessageType::T_NORMAL);
			}
			else
			{

				setConsoleColor(MessageType::T_INFO);
				std::cout << "[INFO]Loading default font Sucessfull..." << std::endl;
				setConsoleColor(MessageType::T_NORMAL);
			}
		
			
		}
		else
		{
			setConsoleColor(MessageType::T_INFO);
			std::cout << "[INFO]Loading default font Sucessfull..." << std::endl;
			setConsoleColor(MessageType::T_NORMAL);
		}
	}
}

GUI::GUIDisplay::GUIDisplay()
{
	this->display = NULL;
	this->sample = NULL;
}

GUI::GUIDisplay::GUIDisplay(int width, int height)
{
	this->display = NULL;
	this->sample = NULL;
	CreateDisplay(width, height);
	this->loadDefaultFont();
	this->playSong();
}

GUI::GUIDisplay::~GUIDisplay()
{
	if(this->display != NULL)
	{
		al_destroy_display(this->display);
	}
	if(this->sample != NULL)
	{
		al_destroy_sample(this->sample);
	}
}

void GUI::GUIDisplay::CreateDisplay(int width, int height)
{
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_OPENGL);
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	this->display = al_create_display(width, height);
	if(!this->display)
	{
		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[ERROR]Creatation display failed!" << std::endl;
		setConsoleColor(MessageType::T_NORMAL);
	}
	else
	{
		al_clear_to_color(al_map_rgb(255, 255, 255));

		//al_flip_display();
		this->setTitle("Binary Search Tree");
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Creatation display Sucessfull..." << std::endl;
		setConsoleColor(MessageType::T_NORMAL);

		//al_rest(10.0);
	}
}

void GUI::GUIDisplay::removeDisplay()
{
	if (this->display != NULL)
	{
		al_destroy_display(this->display);
	}
	if (this->sample != NULL)
	{
		al_destroy_sample(this->sample);
	}
}

void GUI::GUIDisplay::setTitle(std::string title)
{
	if(this->display)
	{
		al_set_window_title(this->display, title.c_str());
	}
}

void GUI::GUIDisplay::printText(std::string text, float x, float y)
{
	if((this->display)&&(this->GUIFont))
	{
		al_draw_text(this->GUIFont, al_map_rgb(0,0,255), x, y, ALLEGRO_ALIGN_CENTRE, text.c_str());
		al_flip_display();
		al_rest(this->delay); //delay/opóżnienie
	}
}

void GUI::GUIDisplay::printVector(float x1, float y1, float x2, float y2)
{
	if(this->display)
	{
		al_draw_line(x1, y1, x2, y2, al_map_rgb(0, 0, 255),2);
		al_flip_display();
	}
}

void GUI::GUIDisplay::clear()
{
	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_flip_display();
}

void GUI::GUIDisplay::playSong()
{
	
	if (!this->sample)
	{
		this->sample = al_load_sample(this->defaultSongPath.c_str());
		if (!this->sample)
		{
			this->sample = al_load_sample(this->defaultRelaseSongPath.c_str());
			if (!this->sample)
			{
				setConsoleColor(MessageType::T_ERROR);
				std::cout << "[ERROR]Loading default song failed!" << std::endl;
				setConsoleColor(MessageType::T_NORMAL);
			}
			else
			{
				setConsoleColor(MessageType::T_INFO);
				std::cout << "[INFO]Loading default song Sucessfull..." << std::endl;
				setConsoleColor(MessageType::T_NORMAL);
				al_play_sample(this->sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			}


		}
		else
		{
			setConsoleColor(MessageType::T_INFO);
			std::cout << "[INFO]Loading default song Sucessfull..." << std::endl;
			setConsoleColor(MessageType::T_NORMAL);
			al_play_sample(this->sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

			
		}
	}
}

void GUI::GUIDisplay::printCircle(float x, float y)
{
	if(this->display)
	{
		al_draw_circle(x, y, this->circle_r, al_map_rgb(0, 0, 255), 2);
		al_flip_display();

	}
}

int GUI::GUIDisplay::getFontSize()
{
	return this->fontSize;
}

float GUI::GUIDisplay::getR()
{
	return this->circle_r;
}

int GUI::GUIDisplay::wait_for_close()
{
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE *a_queue = NULL;
	al_wait_for_event(a_queue, &ev);

	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		return 0;
}


