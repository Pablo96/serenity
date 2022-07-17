/*
 * Copyright (c) 2022, PabloNarvaha <pnarvaja.21@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "TaskbarSettingsWidget.h"

#include <Applications/TaskbarSettings/TaskbarSettingsGML.h>
#include <LibGUI/ConnectionToWindowServer.h>
#include <LibGUI/Margins.h>
#include <LibGUI/BoxLayout.h>
#include <LibGUI/GroupBox.h>

class TaskbarPositionModel final : public GUI::Model {

public:
    TaskbarPositionModel()
    {
        m_color_schemes.empend("Top");
        m_color_schemes.empend("Bottom");
    }

    virtual ~TaskbarPositionModel() = default;

    virtual int row_count(GUI::ModelIndex const& = GUI::ModelIndex()) const override { return 2; }
    virtual int column_count(GUI::ModelIndex const& = GUI::ModelIndex()) const override { return 1; }

    virtual GUI::Variant data(GUI::ModelIndex const& index, GUI::ModelRole role) const override
    {
        if (role == GUI::ModelRole::TextAlignment)
            return Gfx::TextAlignment::CenterLeft;
        if (role == GUI::ModelRole::Display) {
            return m_color_schemes[index.row()];
        }

        return {};
    }

private:
    Vector<String> m_color_schemes;
};

TaskbarSettingsWidget::TaskbarSettingsWidget()
{
    this->set_fill_with_background_color(true);
    this->set_layout<GUI::VerticalBoxLayout>();
    this->layout()->set_margins(10);

    auto& position_groupbox = this->add<GUI::GroupBox>();
    position_groupbox.set_title("Position");
    position_groupbox.set_fixed_height(80);
    position_groupbox.set_layout<GUI::VerticalBoxLayout>();
    position_groupbox.layout()->set_margins(6);
    position_groupbox.layout()->set_spacing(2);
    position_groupbox.add<GUI::Widget>();
    m_position_combobox = position_groupbox.add<GUI::ComboBox>();
    {
        m_position_combobox->set_only_allow_values_from_model(true);
        m_position_combobox->set_model(adopt_ref(*new TaskbarPositionModel()));
        m_position_combobox->set_selected_index(0, GUI::AllowCallback::No);
        m_position_combobox->on_change = [&](String, GUI::ModelIndex) { set_modified(true); };
    }
    position_groupbox.add<GUI::Widget>();

    auto& height_groupbox = this->add<GUI::GroupBox>();
    height_groupbox.set_title("Height");
    height_groupbox.set_fixed_height(80);
    height_groupbox.set_layout<GUI::VerticalBoxLayout>();
    height_groupbox.layout()->set_margins(6);
    height_groupbox.layout()->set_spacing(2);
    height_groupbox.add<GUI::Widget>();
    m_height_valueslider = height_groupbox.add<GUI::ValueSlider>();
    {
        m_height_valueslider->set_range(16, 200);
        m_height_valueslider->set_value(36);
        m_height_valueslider->on_change = [&](auto) { set_modified(true); };
    }
    height_groupbox.add<GUI::Widget>();
}

void TaskbarSettingsWidget::apply_settings()
{
    GUI::ConnectionToWindowServer::the().async_set_taskbar_config(m_height_valueslider->value(), m_position_combobox->selected_index());
}

void TaskbarSettingsWidget::reset_default_values()
{
    m_height_valueslider->set_value(36); // in range (16-200)
    m_position_combobox->set_selected_index(0, GUI::AllowCallback::No); // 0-TOP | 1-BOTTOM
}
