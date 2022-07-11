/*
 * Copyright (c) 2022, MacDue <macdue@dueutil.tech>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "TaskbarSettingsWidget.h"

#include <Applications/TaskbarSettings/TaskbarSettingsGML.h>
#include <LibGUI/ConnectionToWindowServer.h>

TaskbarSettingsWidget::TaskbarSettingsWidget()
{
    load_from_gml(taskbar_settings_gml);
}

void TaskbarSettingsWidget::apply_settings()
{
    //GUI::ConnectionToWindowServer::the().async_set_cursor_highlight_color(highlight_color());
}

void TaskbarSettingsWidget::reset_default_values()
{
    //constexpr auto default_highlight_color = Gfx::Color::NamedColor::Red;
    //constexpr auto default_highlight_opacity = 110; // (in range of 0-255)
    // Disable the highlighting by default.
    // The range of radii you can configure the highlight to is 20 to 60px,
    // anything less than that is treated as 'no highlighting'.
    //constexpr auto default_highlight_radius_length = 25;
    //m_highlight_opacity_slider->set_value(default_highlight_opacity);
    //m_highlight_color_input->set_color(default_highlight_color);
    //m_highlight_radius_slider->set_value(default_highlight_radius_length);
    //deferred_invoke([&] {
    //    // Avoid artifact due to setting both color and opacity sliders:
    //    m_highlight_preview->update();
    //});
}
