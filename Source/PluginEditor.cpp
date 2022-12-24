/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyjuceprojectAudioProcessorEditor::MyjuceprojectAudioProcessorEditor (MyjuceprojectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    // these define the parameters of our slider object
    volumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    volumeSlider.setRange(0.0, 1.0);
    volumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    volumeSlider.setPopupDisplayEnabled(true, false, this);
    volumeSlider.setTextValueSuffix(" Volume");
    volumeSlider.setValue(1.0);

    // this function adds the slider to the editor
    addAndMakeVisible(&volumeSlider);

    volumeSlider.addListener(this);
}

MyjuceprojectAudioProcessorEditor::~MyjuceprojectAudioProcessorEditor()
{
}

//==============================================================================
void MyjuceprojectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::green);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    // fill the whole window white
    g.fillAll(juce::Colours::white);

    // set the current drawing colour to black
    g.setColour(juce::Colours::black);

    // set the font size and draw text to the screen
    g.setFont(15.0f);

    g.drawFittedText("Volume", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void MyjuceprojectAudioProcessorEditor::resized()
{
    // sets the position and size of the slider with arguments (x, y, width, height)
    volumeSlider.setBounds(40, 30, 20, getHeight() - 60);
}

void MyjuceprojectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &volumeSlider)
    {
        // Update the volume processor's volume level based on the slider value
        audioProcessor.setVolume(volumeSlider.getValue());
    }
}
