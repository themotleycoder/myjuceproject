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
    wetDryMixSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    wetDryMixSlider.setRange(0.0, 1.0);
    wetDryMixSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    wetDryMixSlider.setPopupDisplayEnabled(true, false, this);
    wetDryMixSlider.setTextValueSuffix(" Wet/Dry");
    wetDryMixSlider.setValue(0.5);

    // this function adds the slider to the editor
    addAndMakeVisible(&wetDryMixSlider);

    wetDryMixSlider.addListener(this);


    // these define the parameters of our slider object
    roomSizeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    roomSizeSlider.setRange(0.0, 1.0);
    roomSizeSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    roomSizeSlider.setPopupDisplayEnabled(true, false, this);
    roomSizeSlider.setTextValueSuffix(" Room Size");
    roomSizeSlider.setValue(0.5);

    // this function adds the slider to the editor
    addAndMakeVisible(&roomSizeSlider);

    roomSizeSlider.addListener(this);

    // these define the parameters of our slider object
    dampingSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    dampingSlider.setRange(0.0, 1.0);
    dampingSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    dampingSlider.setPopupDisplayEnabled(true, false, this);
    dampingSlider.setTextValueSuffix(" Damping");
    dampingSlider.setValue(0.5);

    // this function adds the slider to the editor
    addAndMakeVisible(&dampingSlider);

    dampingSlider.addListener(this);
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

    g.drawFittedText("Reverb", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void MyjuceprojectAudioProcessorEditor::resized()
{
    // sets the position and size of the slider with arguments (x, y, width, height)
    wetDryMixSlider.setBounds(40, 30, 20, getHeight() - 60);
    roomSizeSlider.setBounds(wetDryMixSlider.getScreenX() + 40, 30, 20, getHeight() - 60);
    dampingSlider.setBounds(roomSizeSlider.getScreenX() + 40, 30, 20, getHeight() - 60);
}

void MyjuceprojectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    //if (slider == &wetDryMixSlider)
    //{
        // Update the volume processor's volume level based on the slider value
        audioProcessor.updateReverb(wetDryMixSlider.getValue(), roomSizeSlider.getValue(), dampingSlider.getValue());
    //}
}
