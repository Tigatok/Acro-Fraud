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
        '#description' => t('What would you consider to be an abnormally large charge?'),
        '#default_value' => variable_get('threshold', 10000),
'#number_type' => 'integer',
        '#element_validate' => array('element_validate_integer')
    );
$form['threshold_settings']['multi_item'] = array(
        '#type' => 'textfield',
        '#title' => t('Multi-Item Transactions'),
        '#description' => t('How many items is an abnormally large transaction'),
        '#default_value' => variable_get('multi_item', 25),
'#number_type' => 'integer',
        '#element_validate' => array('element_validate_integer')

    );

 $form['threshold_settings']['po_box'] = array(
        '#type' => 'textfield',
        '#title' => t('Weight for PO Boxes'),
        '#description' => t('Do you often find fraudulent orders to be associated with PO BOXES. Please add a weight from 0 - 10'),
        '#default_value' => variable_get('po_box', 10),
'#number_type' => 'integer',
        '#element_validate' => array('element_validate_integer')

    );

    return system_settings_form($form);
}

?>
