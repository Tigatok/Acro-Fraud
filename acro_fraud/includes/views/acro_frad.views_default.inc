<?php


function acro_fraud_views_default_views_alter(&$views)
{
    $view = new view();
    $view->name = 'order_risk';
    $view->description = 'displays the risk score of orders';
    $view->tag = 'commerce';
    $view->base_table = 'commerce_order';
    $view->human_name = 'order risk';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = false; /* edit this to true to make a default view disabled initially */

    /* display: master */
    $handler = $view->new_display('default', 'master', 'default');
    $handler->display->display_options['title'] = 'orders';
    $handler->display->display_options['css_class'] = 'commerce-backoffice-view';
    $handler->display->display_options['use_ajax'] = true;
    $handler->display->display_options['use_more_always'] = false;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = false;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['autosubmit'] = true;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '50';
    $handler->display->display_options['style_plugin'] = 'table_megarows';
    $handler->display->display_options['style_options']['columns'] = array(
        'views_bulk_operations' => 'views_bulk_operations',
        'order_number' => 'order_number',
        'created' => 'created',
        'name' => 'name',
        'mail' => 'name',
        'commerce_order_total' => 'commerce_order_total',
        'status' => 'status',
        'operations_dropbutton' => 'operations_dropbutton',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
        'views_bulk_operations' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'order_number' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'created' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'name' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '<br />',
            'empty_column' => 0,
        ),
        'mail' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'commerce_order_total' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'status' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'operations_dropbutton' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
    $handler->display->display_options['style_options']['empty_table'] = true;
    $handler->display->display_options['row_plugin'] = 'fields';
    /* no results behavior: commerce order: empty text */
    $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
    $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
    $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
    /* relationship: commerce order: referenced customer profile */
    $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
    $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
    $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
    /* relationship: commerce order: owner */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* relationship: order risk: link orders to risk */
    $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
    $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_order_risk';
    $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
    $handler->display->display_options['relationships']['order_id']['label'] = 'default label for the relationship';
    /* field: bulk operations: commerce order */
    $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
    $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
    $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
    $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = false;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
        'rules_component::rules_commerce_order_status_canceled' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_commerce_order_status_cart' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_order_status_checkout_checkout' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_order_status_checkout_complete' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_order_status_checkout_payment' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_order_status_checkout_review' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_order_status_checkout_shipping' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_commerce_order_status_completed' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_commerce_order_status_pending' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
        'rules_component::rules_commerce_order_status_processing' => array(
            'selected' => 1,
            'postpone_processing' => 0,
            'skip_confirmation' => 0,
            'override_label' => 0,
            'label' => '',
        ),
    );
    /* field: commerce order: order number */
    $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
    $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
    $handler->display->display_options['fields']['order_number']['label'] = 'id';
    $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
    /* field: user: name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['label'] = 'name/email';
    /* field: user: e-mail */
    $handler->display->display_options['fields']['mail']['id'] = 'mail';
    $handler->display->display_options['fields']['mail']['table'] = 'users';
    $handler->display->display_options['fields']['mail']['field'] = 'mail';
    $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
    $handler->display->display_options['fields']['mail']['label'] = 'email';
    $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
    /* field: commerce order: order total */
    $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
    $handler->display->display_options['fields']['commerce_order_total']['label'] = 'total';
    $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
    $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
        'calculation' => false,
    );
    /* field: commerce order: order status */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    $handler->display->display_options['fields']['status']['label'] = 'status';
    /* field: order risk: risk score */
    $handler->display->display_options['fields']['risk_score']['id'] = 'risk_score';
    $handler->display->display_options['fields']['risk_score']['table'] = 'commerce_order_risk';
    $handler->display->display_options['fields']['risk_score']['field'] = 'risk_score';
    /* field: order risk: reason */
    $handler->display->display_options['fields']['reason']['id'] = 'reason';
    $handler->display->display_options['fields']['reason']['table'] = 'commerce_order_risk';
    $handler->display->display_options['fields']['reason']['field'] = 'reason';
    /* sort criterion: commerce order: updated date */
    $handler->display->display_options['sorts']['changed']['id'] = 'changed';
    $handler->display->display_options['sorts']['changed']['table'] = 'commerce_order';
    $handler->display->display_options['sorts']['changed']['field'] = 'changed';
    $handler->display->display_options['sorts']['changed']['order'] = 'desc';
    /* contextual filter: commerce order: order id */
    $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
    $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
    $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
    $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
    /* filter criterion: commerce order: order status */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['exposed'] = true;
    $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['label'] = 'filter by';
    $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
    $handler->display->display_options['filters']['status']['expose']['multiple'] = true;
    /* filter criterion: date: date (commerce_order) */
    $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
    $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
    $handler->display->display_options['filters']['date_filter']['group'] = 1;
    $handler->display->display_options['filters']['date_filter']['exposed'] = true;
    $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
    $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
    $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
    $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
        'commerce_order.created' => 'commerce_order.created',
    );
    /* filter criterion: global: combine fields filter */
    $handler->display->display_options['filters']['combine']['id'] = 'combine';
    $handler->display->display_options['filters']['combine']['table'] = 'views';
    $handler->display->display_options['filters']['combine']['field'] = 'combine';
    $handler->display->display_options['filters']['combine']['operator'] = 'contains';
    $handler->display->display_options['filters']['combine']['exposed'] = true;
    $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
    $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
    $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
    $handler->display->display_options['filters']['combine']['fields'] = array(
        'order_number' => 'order_number',
        'name' => 'name',
        'mail' => 'mail',
    );

    /* display: admin page */
    $handler = $view->new_display('page', 'admin page', 'admin_page');
    $handler->display->display_options['defaults']['hide_admin_links'] = false;
    $handler->display->display_options['path'] = 'admin/commerce/order-risk';
    $handler->display->display_options['menu']['type'] = 'default tab';
    $handler->display->display_options['menu']['title'] = 'order risk';
    $handler->display->display_options['menu']['weight'] = '-10';
    $handler->display->display_options['tab_options']['type'] = 'normal';
    $handler->display->display_options['tab_options']['title'] = 'order risk';
    $handler->display->display_options['tab_options']['description'] = 'view the risk of orders in the store.';
    $handler->display->display_options['tab_options']['weight'] = '';
    $handler->display->display_options['tab_options']['name'] = 'management';

    /* display: block */
    $handler = $view->new_display('block', 'block', 'block_1');
    $handler->display->display_options['defaults']['fields'] = false;
    /* field: commerce order: order number */
    $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
    $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
    $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
    $handler->display->display_options['fields']['order_number']['label'] = 'id';
    $handler->display->display_options['fields']['order_number']['link_to_order'] = 'admin';
    /* field: order risk: risk score */
    $handler->display->display_options['fields']['risk_score']['id'] = 'risk_score';
    $handler->display->display_options['fields']['risk_score']['table'] = 'commerce_order_risk';
    $handler->display->display_options['fields']['risk_score']['field'] = 'risk_score';
    /* field: order risk: reason */
    $handler->display->display_options['fields']['reason']['id'] = 'reason';
    $handler->display->display_options['fields']['reason']['table'] = 'commerce_order_risk';
    $handler->display->display_options['fields']['reason']['field'] = 'reason';
    $handler->display->display_options['defaults']['filter_groups'] = false;
    $handler->display->display_options['defaults']['filters'] = false;
    $handler->display->display_options['block_description'] = 'risk small block';
}