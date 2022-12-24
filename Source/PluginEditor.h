/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyjuceprojectAudioProcessorEditor  :  public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:
    MyjuceprojectAudioProcessorEditor (MyjuceprojectAudioProcessor&);
    ~MyjuceprojectAudioProcessorEditor() override;

    void sliderValueChanged(juce::Slider* slider) override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyjuceprojectAudioProcessor& audioProcessor;

    juce::Slider volumeSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyjuceprojectAudioProcessorEditor)
};
