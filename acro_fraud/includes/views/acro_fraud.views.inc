<?php

/**
 * Implements hook_views_data()
 */
function acro_fraud_views_data(){
  $data['commerce_order_risk']['table']['group'] = t('Order Risk');

  // Define the base table
  $data['commerce_order_risk']['table']['base'] = array(
    'field' => 'order_id', // This is the identifier field for the view.
    'title' => t('Order Risk'),
    'help' => t('Contains information about an orders risk.'),
    'weight' => -10,
  );

  // Join on commerce_order
  $data['commerce_order_risk']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'commerce_order' => array(
      'left_field' => 'order_id',
      'field' => 'order_id',
    ),
  );

  // Order ID table field.
  $data['commerce_order_risk']['order_id'] = array(
    'title' => t('Order ID'),
    'help' => t('The ID of an Order'),
    'field' => array(
      'handler' => 'commerce_order_handler_field_order',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'commerce_order', // The name of the table to join with.
      'base field' => 'order_id', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Order risk'),
      'title' => t('Link orders to risk'),
      'help' => t('Links the orders to their risk'),
    ),
    'argument' => array(
      'handler' => 'commerce_order_handler_argument_order_order_id',
      'name field' => 'order_number',
      'numeric' => TRUE,
      'validate type' => 'order_id',
    ),
  );

  $data['commerce_order_risk']['reason'] = array(
    'title' => t('Reason'),
    'help' => t('The reason that determines the risk score'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_order_risk']['risk_score'] = array(
    'title' => t('Risk Score'),
    'help' => t('The risk associated with the order.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_order_fraud']['table']['group'] = t('Order Fraud');

  // Define the base table
  $data['commerce_order_fraud']['table']['base'] = array(
    'field' => 'order_id', // This is the identifier field for the view.
    'title' => t('Order Fraud'),
    'help' => t('Contains fraudulent orders.'),
    'weight' => -10,
  );

  // Join on commerce_order
  $data['commerce_order_fraud']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'commerce_order' => array(
      'left_field' => 'order_id',
      'field' => 'order_id',
    ),
  );


  // Order ID table field.
  $data['commerce_order_fraud']['order_id'] = array(
    'title' => t('Order ID'),
    'help' => t('The ID of an Order'),
    // Define a relationship
    'relationship' => array(
      'base' => 'commerce_order', // The name of the table to join with.
      'base field' => 'order_id', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Fraudulent orders'),
      'title' => t('Fraudulent Orders'),
      'help' => t('Shows orders that have been marked fraudulent'),
    ),
  );


  return $data;
}
