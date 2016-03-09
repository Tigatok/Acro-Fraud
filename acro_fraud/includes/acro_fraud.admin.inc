<?php

/**
 * @file
 *
 */

function acro_fraud_admin_settings() {
    $form = array();

    $form['setting1'] = array(
        '#type' => 'fieldset',
        '#title' => t('Setting 1'),
    );

    $form['setting1']['setting1'] = array(
        '#type' => 'textfield',
        '#title' => t('Large Transaction Size'),
        '#description' => t('What would you consider to be an abdnormally large charge?'),
        '#default_value' => variable_get('setting1', 10000),
        '#element_validate' => array('element_validate_integer')

    );


    return system_settings_form($form);
}