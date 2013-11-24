#include "UITextButton.h"
#include "UITextField.h"

namespace star
{
	UITextButton::UITextButton(
		const tstring & name,
		const tstring & file,
		const tstring & text,
		const tstring & fontName,
		const Color & color,
		bool isVertical
		)
		: UIButton(name, file, isVertical)
		, m_pTextField(nullptr)
	{
		for(uint8 i = 0 ; i < 4 ; ++i)
		{
			m_StateColors[i] = color;
		}

		m_pTextField = new UITextField(
			name + _T("_txt"),
			text,
			fontName,
			color
			);

		AddElement(m_pTextField);
	}

	UITextButton::UITextButton(
		const tstring & name,
		const tstring & file,
		const tstring & text,
		const tstring & fontName,
		const tstring & fontPath,
		float32 fontSize,
		const Color & color,
		bool isVertical
		)
		: UIButton(name, file, isVertical)
		, m_pTextField(nullptr)
	{
		for(uint8 i = 0 ; i < 4 ; ++i)
		{
			m_StateColors[i] = color;
		}

		m_pTextField = new UITextField(
			name + _T("_txt"),
			text,
			fontName,
			fontPath,
			fontSize,
			color
			);

		AddElement(m_pTextField);
	}

	UITextButton::~UITextButton()
	{

	}

	void UITextButton::SetIdleColor(const Color & color)
	{
		m_StateColors[uint8(ElementStates::IDLE)] = color;
	}

	void UITextButton::SetHoverColor(const Color & color)
	{
		m_StateColors[uint8(ElementStates::HOVER)] = color;
	}

	void UITextButton::SetClickColor(const Color & color)
	{
		m_StateColors[uint8(ElementStates::CLICK)] = color;
	}

	void UITextButton::SetDisableColor(const Color & color)
	{
		m_StateColors[3] = color;
	}

	void UITextButton::SetText(const tstring & text)
	{
		m_pTextField->SetText(text);
	}

	const tstring & UITextButton::GetText() const
	{
		return m_pTextField->GetText();
	}

	void UITextButton::TranslateText(const vec2& translation)
	{
		m_pTextField->Translate(translation);
	}

	void UITextButton::TranslateText(float32 x, float32 y)
	{
		m_pTextField->Translate(x, y);
	}

	void UITextButton::TranslateTextX(float32 x)
	{
		m_pTextField->TranslateX(x);
	}

	void UITextButton::TranslateTextY(float32 y)
	{
		m_pTextField->TranslateY(y);
	}

	void UITextButton::SetHorizontalAlignmentText(HorizontalAlignment alignment)
	{
		m_pTextField->SetHorizontalAlignment(alignment);
	}

	void UITextButton::SetVerticalAlignmentText(VerticalAlignment alignment)
	{
		m_pTextField->SetVerticalAlignment(alignment);
	}
	
	void UITextButton::SetTextCentered()
	{
		m_pTextField->SetAlignmentCentered();
	}
	
	void UITextButton::GoIdle()
	{
		UIButton::GoIdle();

		m_pTextField->SetColor(m_StateColors[int8(m_ElementState)]);
	}

#ifdef DESKTOP
	void UITextButton::GoHover()
	{
		UIButton::GoHover();

		m_pTextField->SetColor(m_StateColors[int8(m_ElementState)]);
	}
#endif

	void UITextButton::GoClick()
	{
		UIButton::GoClick();

		m_pTextField->SetColor(m_StateColors[int8(m_ElementState)]);
	}

	void UITextButton::GoFreeze()
	{
		UIButton::GoFreeze();

		m_pTextField->SetColor(m_StateColors[DISABLE_STATE_ID]);
	}
}