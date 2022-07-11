@GUI::Frame {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {
        margins: [10]
    }

    @GUI::GroupBox {
        title: "Highlight color"
        fixed_height: 80
        layout: @GUI::VerticalBoxLayout {
            margins: [6]
            spacing: 2
        }

        @GUI::Widget {}

        @GUI::ColorInput {
            name: "highlight_color_input"
            has_alpha_channel: false
        }

        @GUI::Widget {}
    }
}
