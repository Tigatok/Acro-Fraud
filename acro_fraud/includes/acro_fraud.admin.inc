<?php

/**
 * @file
 *
 */

function acro_fraud_admin_settings() {
    $form = array();

    $form['threshold_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Threshold Settings'),
    );

    $form['threshold_settings']['threshold'] = array(
        '#type' => 'textfield',
        '#title' => t('Large Transaction Size'),
        '#description' => t('What would you consider to be an abdnormally large charge?'),
        '#default_value' => variable_get('threshold', 10000),
        '#element_validate' => array('element_validate_integer')
    );

    //Adds developer settings for things like flagging, messages, emails
    $form['developer_settings'] = [
        '#type'=>'checkbox',
        '#title'=>'Developer Settings',
        '#description'=>t("Enable this if you enable developer mode. This will break some functions of the module."),
        '#default_value'=>variable_get('developer_settings',false),
    ];


    return system_settings_form($form);
}