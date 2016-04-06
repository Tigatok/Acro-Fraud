<?php
/**
 * Implements hook_default_rules_configuration().
 */
function acro_fraud_default_rules_configuration(){
  // Set order status : High Risk
  $rules['rules_commerce_order_status_high_risk'] = entity_import('rules_config', '{ "rules_commerce_order_status_high_risk" : {
      "LABEL" : "Set order status : High Risk (Pending)",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "commerce_order" ],
      "USES VARIABLES" : { "order" : { "label" : "Order", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "order" ], "order_status" : "high_risk" } }
      ]
    }
  }');
  // Set order status : Fraudulent
  $rules['rules_commerce_order_status_fraudulent'] = entity_import('rules_config', '{ "rules_commerce_order_status_fraudulent" : {
      "LABEL" : "Set order status : Fraudulent (Canceled)",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "commerce_order" ],
      "USES VARIABLES" : { "order" : { "label" : "Order", "type" : "commerce_order" } },
      "ACTION SET" : [
        { "commerce_order_update_status" : { "commerce_order" : [ "order" ], "order_status" : "fraudulent" } }
      ]
    }
  }');

  return $rules;

}