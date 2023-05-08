/***************************************************************************
 *   Copyright (C) 2009 by Pere Ràfols Soler                               *
 *   sapista2@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "setwidgetcolors.h"

#include "colors.h"

SetWidgetColors::SetWidgetColors() {
    m_Button_BgColorNormal.set_rgba(GDK_COLOR_MACRO(BUTTON_BACKGROUND_R),
                                    GDK_COLOR_MACRO(BUTTON_BACKGROUND_G),
                                    GDK_COLOR_MACRO(BUTTON_BACKGROUND_B), 1.0);
    m_Button_BgColorActive.set_rgba(GDK_COLOR_MACRO(BUTTON_ACTIVE_BG_R),
                                    GDK_COLOR_MACRO(BUTTON_ACTIVE_BG_G),
                                    GDK_COLOR_MACRO(BUTTON_ACTIVE_BG_B), 1.0);
    m_Button_BgColorInactive.set_rgba(GDK_COLOR_MACRO(BUTTON_INACTIVE_BG_R),
                                      GDK_COLOR_MACRO(BUTTON_INACTIVE_BG_G),
                                      GDK_COLOR_MACRO(BUTTON_INACTIVE_BG_B), 1.0);
    m_Button_BgColorOver.set_rgba(GDK_COLOR_MACRO(BUTTON_OVER_BG_R),
                                  GDK_COLOR_MACRO(BUTTON_OVER_BG_G),
                                  GDK_COLOR_MACRO(BUTTON_OVER_BG_B), 1.0);
    m_Button_FgColor.set_rgba(GDK_COLOR_MACRO(FOREGROUND_R), GDK_COLOR_MACRO(FOREGROUND_G),
                              GDK_COLOR_MACRO(FOREGROUND_B), 1.0);
    m_Button_TextColor.set_rgba(GDK_COLOR_MACRO(TEXT_R), GDK_COLOR_MACRO(TEXT_G),
                                GDK_COLOR_MACRO(TEXT_B), 1.0);

    for (int i = 0; i < 10; i++) {
        m_BandsColors[i].set(bandColorLUT[i]);
    }

    // Initialize the ButtonStyle Object
	
	/*
    PlainButtonStyle = Gtk::Style::create();
	*/
	
	// convert from gtkmm2 to gtkmm3
	PlainButtonStyle = Gtk::StyleContext::create();
	
	/*
    // Backround colors
    PlainButtonStyle->set_bg(Gtk::STATE_NORMAL, m_Button_BgColorNormal);
    PlainButtonStyle->set_bg(Gtk::STATE_ACTIVE, m_Button_BgColorActive);
    PlainButtonStyle->set_bg(Gtk::STATE_INSENSITIVE, m_Button_BgColorInactive);
    PlainButtonStyle->set_bg(Gtk::STATE_PRELIGHT, m_Button_BgColorOver);
    PlainButtonStyle->set_bg(Gtk::STATE_SELECTED, m_Button_BgColorNormal);

	PlainButtonStyle.

    // Base colors
    PlainButtonStyle->set_base(Gtk::STATE_NORMAL, m_Button_BgColorNormal);
    PlainButtonStyle->set_base(Gtk::STATE_ACTIVE, m_Button_BgColorActive);
    PlainButtonStyle->set_base(Gtk::STATE_INSENSITIVE, m_Button_BgColorInactive);
    PlainButtonStyle->set_base(Gtk::STATE_PRELIGHT, m_Button_BgColorOver);
    PlainButtonStyle->set_base(Gtk::STATE_SELECTED, m_Button_BgColorNormal);

    // Foreground
    PlainButtonStyle->set_fg(Gtk::STATE_NORMAL, m_Button_FgColor);
    PlainButtonStyle->set_fg(Gtk::STATE_ACTIVE, m_Button_FgColor);
    PlainButtonStyle->set_fg(Gtk::STATE_INSENSITIVE, m_Button_FgColor);
    PlainButtonStyle->set_fg(Gtk::STATE_PRELIGHT, m_Button_FgColor);
    PlainButtonStyle->set_fg(Gtk::STATE_SELECTED, m_Button_FgColor);

    // Text colors
    PlainButtonStyle->set_text(Gtk::STATE_NORMAL, Gdk::Color("#FFFFFF"));
    PlainButtonStyle->set_text(Gtk::STATE_ACTIVE, Gdk::Color("#FFFFFF"));
    PlainButtonStyle->set_text(Gtk::STATE_INSENSITIVE, Gdk::Color("#FFFFFF"));
    PlainButtonStyle->set_text(Gtk::STATE_PRELIGHT, Gdk::Color("#FFFFFF"));
    PlainButtonStyle->set_text(Gtk::STATE_SELECTED, Gdk::Color("#FFFFFF"));
	*/
}

Glib::RefPtr<Gtk::StyleContext> SetWidgetColors::getPlainButtonStyle() { return PlainButtonStyle; }

void SetWidgetColors::setButtonColors(Gtk::Button* widget) {
	widget->override_background_color(m_Button_BgColorNormal, Gtk::STATE_FLAG_NORMAL);
	widget->override_background_color(m_Button_BgColorActive, Gtk::STATE_FLAG_ACTIVE);
	widget->override_background_color(m_Button_BgColorInactive, Gtk::STATE_FLAG_INSENSITIVE);
	widget->override_background_color(m_Button_BgColorOver, Gtk::STATE_FLAG_PRELIGHT);
	widget->override_background_color(m_Button_BgColorNormal, Gtk::STATE_FLAG_SELECTED);

	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_NORMAL);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_ACTIVE);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_INSENSITIVE);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_PRELIGHT);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_SELECTED);

	widget->get_child()->override_color(m_Button_TextColor, Gtk::STATE_FLAG_NORMAL);
	widget->get_child()->override_color(m_Button_TextColor, Gtk::STATE_FLAG_ACTIVE);
	widget->get_child()->override_color(m_Button_TextColor, Gtk::STATE_FLAG_INSENSITIVE);
	widget->get_child()->override_color(m_Button_TextColor, Gtk::STATE_FLAG_PRELIGHT);
	widget->get_child()->override_color(m_Button_TextColor, Gtk::STATE_FLAG_SELECTED);
}

void SetWidgetColors::setGenericWidgetColors(Gtk::Widget* widget) {
	widget->override_background_color(m_Button_BgColorNormal, Gtk::STATE_FLAG_NORMAL);
	widget->override_background_color(m_Button_BgColorActive, Gtk::STATE_FLAG_ACTIVE);
	widget->override_background_color(m_Button_BgColorInactive, Gtk::STATE_FLAG_INSENSITIVE);
	widget->override_background_color(m_Button_BgColorOver, Gtk::STATE_FLAG_PRELIGHT);

	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_NORMAL);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_ACTIVE);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_INSENSITIVE);
	widget->override_color(m_Button_TextColor, Gtk::STATE_FLAG_PRELIGHT);
}

void SetWidgetColors::setBandFrameColor(Gtk::Frame* widget, int band) { 
	widget->override_background_color(m_BandsColors[band], Gtk::STATE_FLAG_NORMAL);
	widget->override_background_color(m_BandsColors[band], Gtk::STATE_FLAG_ACTIVE);
	widget->override_background_color(m_BandsColors[band], Gtk::STATE_FLAG_INSENSITIVE);
	widget->override_background_color(m_BandsColors[band], Gtk::STATE_FLAG_PRELIGHT);

	widget->override_color(m_BandsColors[band], Gtk::STATE_FLAG_NORMAL);
	widget->override_color(m_BandsColors[band], Gtk::STATE_FLAG_ACTIVE);
	widget->override_color(m_BandsColors[band], Gtk::STATE_FLAG_INSENSITIVE);
	widget->override_color(m_BandsColors[band], Gtk::STATE_FLAG_PRELIGHT);

	widget->get_label_widget()->override_color(m_BandsColors[band], Gtk::STATE_FLAG_NORMAL);
	widget->get_label_widget()->override_color(m_BandsColors[band], Gtk::STATE_FLAG_ACTIVE);
	widget->get_label_widget()->override_color(m_BandsColors[band], Gtk::STATE_FLAG_INSENSITIVE);
	widget->get_label_widget()->override_color(m_BandsColors[band], Gtk::STATE_FLAG_PRELIGHT);
}
