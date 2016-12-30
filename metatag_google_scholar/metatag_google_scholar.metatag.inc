<?php
/**
 * @file
 * Metatag integration for the Metatag:Google Scholar module.
 */

/**
 * Implements hook_metatag_info().
 */
function metatag_google_scholar_metatag_info() {
  $info['groups']['google-scholar'] = array(
    'label' => t('Google Scholar Metatags'),
    'description' => t("Google Scholar uses automated software, known as 'parsers', to identify bibliographic data of your papers, as well as references between the papers. Incorrect identification of bibliographic data or references will lead to poor indexing of your site. Some documents may not be included at all, some may be included with incorrect author names or titles, and some may rank lower in the search results, because their (incorrect) bibliographic data would not match (correct) references to them from other papers. To avoid such problems, you need to provide bibliographic data and references in a way that automated \"parser\" software can process."),
  );

  // Google Scholar meta tags stack after the simple tags.
  $weight = 80;

  // Default values for each meta tag.
  $tag_info_defaults = array(
    'description' => '',
    'class' => 'DrupalTextMetaTag',
    'group' => 'google-scholar',
  );

  $info['tags']['citation_title'] = array(
    'label' => t('Title'),
    'description' => t("The citation_title must contain the title of the paper. Don't use it for the title of the journal or a book in which the paper was published, or for the name of your repository. This tag is required for inclusion in Google Scholar."),
  ) + $tag_info_defaults;

  $info['tags']['citation_author'] = array(
    'label' => t('Author(s)'),
    'description' => t("The citation_author must contain the authors (and only the actual authors) of the paper. Don't use it for the author of the website or for contributors other than authors, e.g., thesis advisors. Author names can be listed either as \"Smith, John\" or as \"John Smith\". Omit all affiliations, degrees, certifications, etc., from this field. At least one author tag is required for inclusion in Google Scholar."),
    'multiple' => TRUE,
  ) + $tag_info_defaults;

  $info['tags']['citation_publication_date'] = array(
    'label' => t('Publication Date'),
    'description' => t("The citation_publication_date must contain the date of publication, i.e., the date that would normally be cited in references to this paper from other papers. Don't use it for the date of entry into the repository - that should go into citation_online_date instead. Provide full dates in the \"2010/5/12\" format if available; or a year alone otherwise. This tag is required for inclusion in Google Scholar."),
  ) + $tag_info_defaults;

  $info['tags']['citation_online_date'] = array(
    'label' => t('citation_online_date'),
    'description' => t("Date of entry into the repository"),
  ) + $tag_info_defaults;

  $info['tags']['citation_journal_title'] = array(
    'label' => t('Journal Title'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_conference_title'] = array(
    'label' => t('Conference Title'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_isbn'] = array(
    'label' => t('citation_isbn'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_issn'] = array(
    'label' => t('citation_issn'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_volume'] = array(
    'label' => t('citation_volume'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_issue'] = array(
    'label' => t('citation_issue'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_firstpage'] = array(
    'label' => t('citation_firstpage'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_lastpage'] = array(
    'label' => t('citation_lastpage'),
    'description' => t("For journal and conference papers"),
  ) + $tag_info_defaults;

  $info['tags']['citation_dissertation_institution'] = array(
    'label' => t('citation_dissertation_institution'),
    'description' => t("For theses, dissertations, and technical reports"),
  ) + $tag_info_defaults;

  $info['tags']['citation_technical_report_institution'] = array(
    'label' => t('citation_technical_report_institution'),
    'description' => t("For theses, dissertations, and technical reports"),
  ) + $tag_info_defaults;

  $info['tags']['citation_technical_report_number'] = array(
    'label' => t('citation_technical_report_number'),
    'description' => t("For theses, dissertations, and technical reports"),
  ) + $tag_info_defaults;

  $info['tags']['citation_pdf_url'] = array(
    'label' => t('citation_pdf_url'),
    'description' => t("If this page shows only the abstract of the paper and you have the full text in a separate file, e.g., in the PDF format, please specify the locations of all full text versions using citation_pdf_url."),
  ) + $tag_info_defaults;

  return $info;
}

/**
 * Implements hook_metatag_bundled_config_alter().
 */
function metatag_google_scholar_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array();
        break;

      case 'global:frontpage':
        $config->config += array();
        break;

      case 'node':
        $config->config += array(
          'citation_title' => array('value' => '[node:title]'),
        );
        break;

      case 'taxonomy_term':
        $config->config += array();
        break;

      case 'user':
        $config->config += array();
        break;
    }
  }
}