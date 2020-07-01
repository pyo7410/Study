package com.springbook.view.board;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import com.springbook.biz.board.BoardVO;
import com.springbook.biz.board.impl.BoardDAO;

// BoardController로 기존에 기능별로 있던 Controller를 통합하여 관리할 수 있다.
// 기존의 Controller들은 삭제해도 된다.

// ModelAndView보다 String을 사용하는 것이 조금 더 간결하기 때문에 대부분 String으로 통일

@Controller
@SessionAttributes("board")
public class BoardController {
	
	// 검색 조건 목록 설정
	// @ModelAttribute는 LoginController에서 이름 변경 뿐만아니라 View(jsp)에서 사용할 데이터를 설정하는 용도로도 사용된다.
	// @ModelAttribute가 설정된 메소드는 @RequestMapping 어노테이션이 적용된 메소드보다 먼저 호출된다.
	// @ModelAttribute 메소드 실행 결과로 리턴된 객체는 자동으로 Model에 저장된다.
	// @ModelAttribute 메소드의 실행 결과로 리턴될 객체를 View 페이지에서 사용할 수 있다.
	@ModelAttribute("conditionMap")
	public Map<String, String> searchConditionMap() {
		Map<String, String> conditionMap = new HashMap<String, String>();
		conditionMap.put("제목", "TITLE");
		conditionMap.put("내용", "CONTENT");
		return conditionMap;
	}

	// 글 등록
	// RequestMapping은 HandlerMapping 설정을 대체하기 위한 어노테이션
	// value 설정은 특별한 경우가 아니라면 대부분 생략한다.

	// Command 객체를 이용, insertBoard() 메소드를 실행할 때 스프링 컨테이너가 Command 객체를 생성하여 넘겨주고 사용자가
	// 입력한 값들 까지도 Command 객체에 세팅해서 넘겨준다.
	// 즉, 결과적으로 사용자 입력 정보 추출과 VO 객체 생성, 그리고 값 설정을 모두 컨테이너가 자동으로 처리된다.
	// 중요한 점은 Form 태그안의 파라미터 ㅣ름과 Command 객체의 Setter 메소드 이름이 반드시 일치해야 한다.
	// 즉, 각 파라미터 이름에 해당하는 메소드가 있어야 Setter 인젝션에 의해 자동으로 사용자 입력값이 저장된다.
	@RequestMapping(value = "/insertBoard.do")
	public String insertBoard(BoardVO vo, BoardDAO boardDAO) {
		System.out.println("글 등록 처리");

		boardDAO.insertBoard(vo);
		// 포워딩은 예를 들어 글 등록 후에 목록 화면이 출려고디도 브라우저의 URL은 변경안되는 것을 의미 (return
		// "getBoardList.do"; -> http://localhost:8090/BoardWeb/insertBoard.do)
		// 리다이렉트는 글 등록 처리 후에 리다이렉트에 해당되는 URL로 변경 (return "redirect:getBoardList.do; ->
		// http://localhost:8090/BoardWeb/getBoardList.do)
		return "getBoardList.do";
	}

	// 글 수정
	// 사용자가 상세 화면을 요청하면 getBoard() 메소드는 검색 결과인 BoardVO 객체를 board라는 이름으로 Model에 저장한다.
	// 이때 BoardController 클래스에 선언된 @SessionAttributes("board")설정에 의해 Model에 "board"라는 이름으로 저장되는 데이터가 있다면
	// 그 데이터를 세션(HttpSession)에도 자동으로 저장하라는 설정이다.
	// 따라서 getBoard() 메소드가 실행되어 상세 화면이 출력되면 일차적으로 Model에 board라는 이름으로 BoardVO 객체가 저장되고 
	// 세션에도 board라는 이름으로 BoardVO 객체가 저장된다.
	
	// 사용자가 글 수정 버튼을 클릭하면, updateBoard() 메소드가 실행되고 이때 스프링 컨테이너는 우선 @ModelAttribute("board") 설정을 해석하여
	// 세션에 board라는 이름으로 저장된 데이터가 있는지를 확인한다.
	// 그리고 있다면 해당 객체를 세션에서 꺼내서 매개변수로 선언된 vo 변수에 할당한다.
	// 이때 사용자가 입력한 수정 정보값만 새롭게 할당된다.
	@RequestMapping("/updateBoard.do")
	public String updateBoard(@ModelAttribute("board") BoardVO vo, BoardDAO boardDAO) {
		System.out.println("글 수정 처리");

		System.out.println("번호 : " + vo.getSeq());
		System.out.println("제목 :" + vo.getTitle());
		System.out.println("작성자 : " + vo.getWriter());
		System.out.println("내용 : " + vo.getContent());
		System.out.println("등록일 : " + vo.getRegDate());
		System.out.println("조회수 : " + vo.getCnt());

		boardDAO.updateBoard(vo);
		return "getBoardList.do";
	}

	// 글 삭제
	@RequestMapping("/deleteBoard.do")
	public String deleteBoard(BoardVO vo, BoardDAO boardDAO) {
		System.out.println("글 삭제 처리");

		boardDAO.deleteBoard(vo);
		return "getBoardList.do";
	}

	// ModelAndView
	/*
	// 글 상세 조회
	@RequestMapping("/getBoard.do") public ModelAndView getBoard(BoardVO vo, BoardDAO boardDAO, ModelAndView mav) { 
		System.out.println("글 상세 조회 처리");

		// 3. 검색 결과와 화면 정보를 ModelAndView에 저장하여 리턴한다. mav.addObject("board",
		boardDAO.getBoard(vo)); // Model 정보 저장
		mav.setViewName("getBoard.jsp"); // View 정보 저장 
		return mav; 
	}
		
	// 글 목록 검색 
	@RequestMapping("/getBoardList.do") public ModelAndView getBoardList(BoardVO vo, BoardDAO boardDAO, ModelAndView mav) { 
		System.out.println("글 목록 검색 처리");
	
		// 3. 검색 결과와 화면 정보를 ModelAndView에 저장하여 리턴하다. 
		mav.addObject("boardList", boardDAO.getBoardList(vo)); // Model 정보 저장
		mav.setViewName("getBoardList.jsp"); // View 정보 저장 
		return mav; 
	}
	*/

	// String
	// 글 상세 조회
	@RequestMapping("/getBoard.do")
	public String getBoard(BoardVO vo, BoardDAO boardDAO, Model model) {
		System.out.println("글 상세 조회 처리");

		model.addAttribute("board", boardDAO.getBoard(vo)); // Model 정보 저장
		return "getBoard.jsp"; // View 이름 리턴
	}

	// 글 목록 검색
	
	// @RequestParam을 사용하면 Command 객체에는 없는 파라미터를 Controller 클래스에서 사용이 가능하다.
	// HttpServltRequest에서 제공하는 getParameter() 메소드와 같은 기능의 어노테이션이다.
	// 속성의 의미는
	// value : 화면으로부터 전달될 파라미터 이름
	// defaultValue : 화면으로부터 전달될 파라미터의 정보가 없을 때, 설정할 기본값
	// required : 파라미터의 생략 여부
	// 만약 @RequestParam을 사용하기 싫다면 BoardVO 클래스에 searchCondition, searchKeyword 변수를 추가하고 Getter/Setter 메소드만 추가하면 된다.
	@RequestMapping("/getBoardList.do")
	public String getBoardList(@RequestParam(value="searchCondition", defaultValue="TITLE", required=false) String condition,
			                   @RequestParam(value="searchKeyword", defaultValue="", required=false) String keyword, 
			                   BoardVO vo, BoardDAO boardDAO, Model model) {
		System.out.println("글 목록 검색 처리");
		
		System.out.println("검색 조건 : " + condition);
		System.out.println("검색 단어 : " + keyword);

		// Model 정보 저장
		model.addAttribute("boardList", boardDAO.getBoardList(vo));
		return "getBoardList.jsp";
	}

}
