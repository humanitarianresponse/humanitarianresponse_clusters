<?php
/**
 * @file
 * humanitarianresponse_clusters.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function humanitarianresponse_clusters_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_clusters';
  $feeds_importer->config = array(
    'name' => 'CSV Clusters',
    'description' => 'Import clusters from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'bundle' => 'clusters',
        'mappings' => array(
          0 => array(
            'source' => 'Name:en',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Name:en',
            'target' => 'name_field:et:en',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name:fr',
            'target' => 'name_field:et:fr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Name:es',
            'target' => 'name_field:et:es',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Prefix',
            'target' => 'field_cluster_prefix',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['csv_clusters'] = $feeds_importer;

  return $export;
}
